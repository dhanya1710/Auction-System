# Auction System

A console-based C++ auction application that supports item registration, bidder registration, and turn-based multi-player bidding.

## Features

- Add auction items dynamically
- Register multiple bidders
- Start auction for a selected item
- Enforce minimum bid increment rules
- Display live highest bid and bidder
- End auction when all bidders skip
- Show final winner for the item

## Project Structure

- `miniproject25cs111.cpp` - Main source code
- `miniproject25cs111.exe` - Compiled executable (Windows)
- `miniproject25cs111.o` - Object file

## Requirements

- C++ compiler (g++ recommended)
- Terminal/Command Prompt

## Compile and Run

```bash
g++ miniproject25cs111.cpp -o miniproject25cs111
./miniproject25cs111
```

On Windows (PowerShell), run:

```powershell
g++ miniproject25cs111.cpp -o miniproject25cs111.exe
.\miniproject25cs111.exe
```

## How It Works

1. Add one or more auction items.
2. Add one or more bidders.
3. Start auction by selecting an item ID.
4. Each bidder can either place a bid or skip in each round.
5. Auction ends when all bidders skip in a round.
6. The system announces the winner (highest bidder).

## Notes

- Item names and bidder names are read with standard input tokens.
- If names contain spaces, input handling can be extended with `getline`.

## Author

Dhanya
