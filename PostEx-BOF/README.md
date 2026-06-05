# PostEx-BOF

Post-exploitation BOFs: find-flags, ...

## find-flags

Recursively search the `C:\` drive for common CTF flag files (e.g., `user.txt`, `root.txt`, `flag.txt`) and print their contents to the output buffer.

```
find-flags
```

### Details
- **Target Files**: `user.txt`, `root.txt`, `local.txt`, `proof.txt`, `secret.txt`, `flag.txt`.
- **Exclusions**: Automatically skips common system directories like `Windows` and `Program Files` to reduce noise and execution time.
- **Output**: Prints the path of each found flag followed by its content.
