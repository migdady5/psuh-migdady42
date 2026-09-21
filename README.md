# migdady5\n\n*This activity has been created as part of the 42 curriculum by amigdadi, tmeqdad.*

# push_swap

## Description
`push_swap` is a sorting program written in C that sorts a stack of integers in ascending order using only the operations allowed by the subject.

The project starts with two stacks:
- **stack a** contains the input numbers
- **stack b** starts empty

The goal is to print a valid sequence of push_swap operations that sorts `stack a` with the lowest possible number of moves.

This version of the project follows the updated subject requirements and embeds **four strategies** inside the same binary:
- a **simple** strategy in `O(n²)`
- a **medium** strategy in `O(n√n)`
- a **complex** strategy in `O(n log n)`
- an **adaptive** strategy that chooses the internal method depending on the measured disorder of the input

The program also supports an optional `--bench` mode that prints metrics to `stderr`, including disorder, selected strategy, total number of operations, and per-operation counters, as required by the subject. fileciteturn0file0

---

## Project Goals
This project is designed to build a concrete understanding of:
- algorithmic complexity
- constrained sorting
- stack manipulation
- input parsing and validation
- performance trade-offs between multiple strategies

Because operations are limited, the problem is not only about sorting correctly, but also about choosing the right method for the input shape and size. The subject explicitly requires the complexity to be reasoned about in terms of **generated push_swap operations**, not classical array-only complexity. fileciteturn0file0

---

## Features
- Parses integers from command line arguments
- Rejects invalid numbers, duplicates, and out-of-range values
- Handles both positive and negative integers
- Supports the following selector flags:
  - `--simple`
  - `--medium`
  - `--complex`
  - `--adaptive`
  - `--bench`
- Uses `--adaptive` as the default strategy when no selector is provided
- Prints `Error` to `stderr` on invalid input
- Produces only valid push_swap instructions on `stdout`
- Reports benchmark details on `stderr` only when `--bench` is enabled fileciteturn0file0

---

## Allowed Operations
The program generates only the operations allowed by the subject:

- `sa`
- `sb`
- `ss`
- `pa`
- `pb`
- `ra`
- `rb`
- `rr`
- `rra`
- `rrb`
- `rrr` fileciteturn0file0

---

## Instructions
### Compilation
```bash
make
```

Required Makefile rules:
```bash
all
clean
fclean
re
```

The project must compile with:
```bash
-Wall -Wextra -Werror
```
using `cc`, and the Makefile must not relink. Global variables are forbidden. fileciteturn0file0

### Execution
Basic usage:
```bash
./push_swap 2 1 3 6 5 8
```

Force a specific strategy:
```bash
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
```

Enable benchmark mode:
```bash
./push_swap --bench 4 67 3 87 23
```

Use with checker:
```bash
ARG="4 67 3 87 23"
./push_swap --complex $ARG | ./checker_linux $ARG
```

Save benchmark output while piping moves to checker:
```bash
ARG="4 67 3 87 23"
./push_swap --bench --adaptive $ARG 2> bench.txt | ./checker_linux $ARG
cat bench.txt
```

If no arguments are provided, the program must print nothing. In case of invalid input, it must print `Error` followed by a newline to `stderr`. fileciteturn0file0

---

## Benchmark Mode
When `--bench` is present, the program must print the following information to `stderr` after sorting:
- disorder percentage with two decimals
- selected strategy name
- theoretical complexity class
- total number of operations
- count of each operation type

This output must appear only in benchmark mode and must never pollute the normal operation stream on `stdout`. fileciteturn0file0

Example format:
```text
[bench] disorder: 40.00%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 13
[bench] sa: 0 sb: 0 ss: 0 pa: 5 pb: 5
[bench] ra: 2 rb: 1 rr: 0 rra: 0 rrb: 0 rrr: 0
```

---

## Disorder Metric
The subject requires measuring **disorder** before doing any move.

Disorder is a value between `0` and `1`:
- `0` means the input is already sorted
- `1` means the input is in the worst possible order
- anything in between reflects how unsorted the stack is

It is computed by counting inversions:
- for every pair `(a[i], a[j])` where `i < j`
- if `a[i] > a[j]`, this pair counts as a mistake
- disorder = `mistakes / total_pairs`

This metric is used by the adaptive mode to choose the internal strategy. fileciteturn0file0

---

## Algorithm Design and Justification
The subject requires four distinct strategies inside the same program, with selection at runtime. fileciteturn0file0

### 1) Simple Strategy: `O(n²)`
**Chosen approach:** min-extraction / selection-style sorting

#### Idea
The simple mode repeatedly finds the smallest value in `stack a`, brings it to the top with the cheaper direction (`ra` or `rra`), pushes it to `stack b`, and repeats until only a sorted remainder is left. Then the values are pushed back to `stack a`.

#### Why this fits
This is one of the cleanest baseline strategies for push_swap:
- easy to implement
- easy to defend in evaluation
- predictable behavior
- naturally falls in the `O(n²)` class in terms of generated operations

Each iteration scans for a target and performs rotations plus pushes. Repeating this across the whole stack gives a quadratic upper bound.

#### Why keep it
Even if it is not the fastest on large inputs, it is a solid reference implementation and a reliable fallback for small cases.

### 2) Medium Strategy: `O(n√n)`
**Chosen approach:** chunk-based sorting

#### Idea
The values are first normalized to ranks. Then the input range is divided into about `√n` chunks. The algorithm pushes values from `stack a` to `stack b` chunk by chunk, using rotations to bring values from the active chunk efficiently. Once pushed, values in `stack b` are arranged so recovery is cheaper. Finally, the values are returned to `stack a` in sorted order.

#### Why this fits
Chunk-based sorting is one of the most practical ways to target the `O(n√n)` family in push_swap:
- the number of chunks is around `√n`
- each chunk handles only a limited range
- rotations are distributed instead of blindly scanning the full structure every time

This gives a much better operation profile than the simple method on medium and large inputs, while remaining easier to reason about than a more advanced fully logarithmic design.

#### Why keep it
This is a strong middle-ground strategy:
- better than quadratic approaches on larger inputs
- easier to debug than aggressive optimizers
- maps naturally to the subject requirement for the medium-complexity class

### 3) Complex Strategy: `O(n log n)`
**Chosen approach:** radix sort on normalized indices

#### Idea
All values are first converted to their sorted rank (`0..n-1`). Then the algorithm processes the ranks bit by bit from least significant bit to most significant bit:
- if the current bit is `0`, push to `stack b`
- if the current bit is `1`, rotate `stack a`
- after one full pass, push everything back from `stack b` to `stack a`

#### Why this fits
Radix on indices is a classic and well-proven push_swap solution:
- no comparisons between raw values are needed during sorting
- negative numbers are handled naturally once normalized
- the number of passes is proportional to the number of bits, which is `log n`
- each pass touches the full dataset in a controlled way

This gives an `O(n log n)` upper bound in the push_swap operation model and is usually the best general-purpose choice for large random inputs.

#### Why keep it
It is stable, efficient, and easy to justify mathematically during defense.

### 4) Adaptive Strategy
**Chosen approach:** disorder-driven dispatcher

The adaptive strategy measures disorder first, then chooses a specialized internal method depending on how far the stack is from sorted. The thresholds are based directly on the subject requirements. fileciteturn0file0

#### Regime A: low disorder (`disorder < 0.2`) -> target `O(n)`
**Internal method:** near-sorted linear repair

For nearly sorted inputs, the algorithm avoids heavy partitioning. It performs a linear pass and fixes only local disruptions using small targeted operations such as:
- limited rotations
- local swaps
- minimal push/restore behavior only when needed

#### Justification
When the stack is already close to sorted, a full chunk or radix routine wastes operations. A near-sorted repair path can exploit the existing order and keep the move count proportional to the number of local defects, giving a linear upper bound for this restricted regime.

#### Regime B: medium disorder (`0.2 <= disorder < 0.5`) -> target `O(n√n)`
**Internal method:** chunk-based sorting

This regime uses the same chunk strategy as the medium algorithm. At this level of disorder, the input is not sorted enough for linear repair, but it still benefits from structured partitioning without paying the full overhead of a logarithmic general-purpose approach.

#### Regime C: high disorder (`disorder >= 0.5`) -> target `O(n log n)`
**Internal method:** radix sort on indices

Highly disordered input behaves much closer to random data. In this case, radix provides the best predictable performance and the cleanest upper bound.

### Threshold Rationale
The thresholds are chosen to match the subject contract while keeping the decision understandable:
- below `0.2`: the stack is close enough to sorted that preserving structure is cheaper than repartitioning
- from `0.2` to below `0.5`: disorder is noticeable but not extreme, which makes chunking a good compromise
- from `0.5` and above: the input is sufficiently chaotic that radix becomes the safest high-performance option

### Space Complexity Notes
All strategies operate within the push_swap model using only the two stacks and small helper structures:
- simple: `O(n)` storage for the linked-list stack representation
- medium: `O(n)` including index/rank metadata
- complex: `O(n)` including normalized ranks
- adaptive: same as the selected internal strategy

---

## Input Validation
The parser must reject:
- non-integer tokens
- duplicates
- values outside the `int` range
- malformed numeric strings

Accepted input may include:
- positive values
- negative values
- already sorted sequences
- a single number

If the input is invalid, the program must print:
```text
Error
```
to `stderr`. fileciteturn0file0

---

## Performance Targets
According to the subject, the expected benchmarks are: 

### For 100 random numbers
- less than `2000` operations to pass
- less than `1500` for good performance
- less than `700` for excellent performance

### For 500 random numbers
- less than `12000` operations to pass
- less than `8000` for good performance
- less than `5500` for excellent performance fileciteturn0file0

These targets were used as a practical reference when choosing the default behavior of the adaptive mode.

---

## Contribution Breakdown
This project is a group activity and must be completed by exactly two learners, both of whom should understand the whole implementation and be able to explain any part during defense. fileciteturn0file0

### amigdadi
- parser and validation flow
- stack initialization and memory management
- primitive operations and operation logging
- README writing and project integration

### tmeqdad
- sorting strategy implementation
- disorder computation and adaptive selection
- benchmarking counters and metrics formatting
- testing and performance verification

### Shared work
- algorithm review and cleanup
- norm fixes
- checker-based validation
- peer-defense preparation

> Replace this section if your real split was different. What matters is that the README clearly shows meaningful contribution from both learners.

---

## Error Handling and Testing
Recommended checks:
```bash
./push_swap
./push_swap 1
./push_swap 2 1
./push_swap 3 2 1
./push_swap 1 2 3
./push_swap 0 one 2 3
./push_swap 3 2 3
./push_swap --bench 4 67 3 87 23
```

Useful large-input test:
```bash
shuf -i 0-9999 -n 500 > args.txt
./push_swap --adaptive $(cat args.txt) | wc -l
./push_swap --adaptive $(cat args.txt) | ./checker_linux $(cat args.txt)
```

---

## Resources
### Classic references
- 42 subject PDF for `push_swap`
- Big-O notation overview
- Stack abstract data type references
- radix sort references
- chunk/range-based sorting discussions for push_swap practice

### How AI was used
AI was used only as a support tool for:
- discussing algorithm choices
- comparing strategy trade-offs
- reviewing README structure and wording
- helping think through edge cases and testing ideas

All final code, logic decisions, and project understanding were reviewed manually and are expected to be explainable during evaluation, which is consistent with the subject’s guidance on responsible AI usage. fileciteturn0file0

---

## Final Notes
This project is not only about producing a sorted result. It is about choosing the right method under strict constraints, defending the complexity of that choice, and writing a solution that remains correct, clean, testable, and explainable.

A valid `push_swap` should therefore be:
- correct
- leak-free
- norm-compliant
- explainable in defense
- efficient enough to meet the benchmark targets

