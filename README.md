*This activity has been created as part of the 42 curriculum by amigdadi, tmeqdad.*

## Description
`push_swap` sorts integers in ascending order using two stacks (`a` and `b`) and a fixed instruction set (`sa`, `pb`, `ra`, etc.).

This version embeds four strategies and can switch at runtime:
- **Simple**: minimum extraction (quadratic behavior)
- **Medium**: chunk-based partitioning
- **Complex**: binary radix sort on indexed values
- **Adaptive**: strategy chosen from measured disorder

## Instructions
### Build
```bash
make
```

### Run
```bash
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] <numbers...>
```

Notes:
- Default strategy is `--adaptive` when no strategy flag is given.
- `--bench` prints metrics to `stderr` while operations remain on `stdout`.

### Error handling
The program prints `Error` to `stderr` for invalid integers, overflow, duplicates, or invalid flags.

## Algorithm choices and complexity rationale
### Disorder metric
Disorder is computed as inversion ratio:
- `0.0`: already sorted
- `1.0`: maximally inverted

### Strategy details
1. **Simple O(n²)**
   - Repeatedly bring the minimum to top of `a`, push to `b`, then restore to `a`.
   - Cost is quadratic due to repeated scans and rotations.

2. **Medium O(n*sqrt(n)) (targeted chunk strategy)**
   - Split indexed range into chunks and push chunk members to `b`.
   - Rebuild `a` by extracting descending maxima from `b`.

3. **Complex O(n log n)**
   - LSD radix sort over normalized indexes.
   - For each bit, push 0-bit indexes to `b`, rotate 1-bit in `a`, then restore from `b`.

4. **Adaptive**
   - Thresholds:
     - `disorder < 0.20` → Simple
     - `0.20 <= disorder < 0.50` → Medium
     - `disorder >= 0.50` → Complex
   - Rationale: near-sorted inputs are handled with a conservative strategy, medium disorder benefits from chunking, and high disorder is handled by radix.

### Space usage
All strategies operate on linked-stack nodes plus small helper variables. Indexing uses a temporary array of size `n`.

## Group contributions
- **amigdadi**: core sorting dispatch, small-size sort paths (`sort_3`, `sort_5`), flag parsing base.
- **tmeqdad**: stack building, validation utilities, operation primitives, chunk sorting, disorder/index support.
- **Shared updates**: runtime strategy integration, benchmark output wiring, radix/adaptive completion, and README alignment.

## Resources
- 42 subject PDF (project specification)
- Donald Knuth, *The Art of Computer Programming* (sorting references)
- Big-O notation references from standard CS curriculum

### AI usage
AI was used for:
- repetitive refactoring of function prototypes and plumbing,
- drafting and refining benchmark output formatting,
- generating and reviewing algorithm scaffolding (radix/adaptive),
- README structuring.

All generated material was manually reviewed, tested, and adjusted before commit.
