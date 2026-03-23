# ⌨️ Balthazar Keyboard Distribution — Dvorak

Baltazar (or Balthazar) is a name of Akkadian origin meaning *"Bel protects the King."* Commonly known as one of the Biblical Magi — the wise men who traveled great distances guided by a star, bearing gifts of purpose and precision.

This keymap bears that name not by coincidence. Just as Balthazar protected royalty, **this layout protects the programmer**: from RSI, from inefficiency, from the tyranny of stretching fingers across a full-size keyboard. This variant goes further — **Dvorak** places the most common letters of the English language on the home row, reducing finger travel to a minimum.

Built for the **Corne (CRKBD) v3 MX Hotswap** with **Elite-Pi (RP2040)** MCU — on **QMK firmware**. Designed to work seamlessly on both **macOS and Windows**, with cross-platform navigation, ergonomic modifier placement, and a symbol layer engineered for modern programming workflows.

---

## Hardware & Build

- **Keyboard:** Corne MX Hotswap v3.0.1 — 42 keys, split, ortholinear
- **MCU:** Elite-Pi (RP2040) — drop-in Pro Micro replacement
- **Firmware:** QMK
- **Compile target:** `crkbd/rev1` with `CONVERT_TO=elite_pi`
- **Keymap name:** `balthazar_dvorak`
- **Features enabled:** RGB Matrix · OLED display · Encoder support

---

## Flashing Instructions

1. Disconnect the TRRS cable between both halves
2. Connect one half via USB
3. **Press the reset button twice quickly** — a drive called `RPI-RP2` will appear in the file explorer
4. Copy the `.uf2` file to that drive — it flashes automatically and disconnects
5. Repeat with the other half
6. Reconnect the TRRS cable

**Compile:**
```bash
qmk compile -kb crkbd/rev1 -km balthazar_dvorak -e CONVERT_TO=elite_pi
```
The `.uf2` file will be located at `qmk_firmware/.build/`

---

## Layer Overview

### Layer 0 — DVORAK

The foundation. Standard Dvorak layout — home row carries the most frequent English letters (`A O E U I` left / `D H T N S` right), dramatically reducing finger travel. Key ergonomic decisions:

- **`LSFT_T(Tab)`** on the left pinky home row — tap = Tab / hold = Shift. Tab on home row without losing Shift.
- **`ESC`** at top-left — accessible without leaving the base layer.
- **`ENT`** on right pinky home row — no stretch needed.
- **`-`** at bottom-right — `'` is already in the Dvorak top row, so `-` takes that slot instead.
- Left inner thumb doubles as Numpad access via hold.

```
ESC   '   ,   .   P   Y  |  F   G   C   R   L   BSP
TAB/SFT A O   E   U   I  |  D   H   T   N   S   ENT
CTL   ;   Q   J   K   X  |  B   M   W   V   Z   -
          GUI MO(1) LT(3,SPC) | SPC MO(2) ALT
```

**Thumb cluster:**
- Left: `GUI` · `MO(1)` (hold → Navigate) · `LT(3, Space)` (tap → Space / hold → Numpad)
- Right: `Space` · `MO(2)` (hold → Symbols) · `Alt`

---

### Layer 1 — Navigate

Hold left thumb `MO(1)` to activate. Right hand navigates freely.

```
TAB   ·   ·    ·    ·    ·   |   _   ·  PGDN PGUP PSCR  BSP
 ·    ·  SFT  ALT  CTL   ·   | HOME  ←    ↓    ↑    →   DEL
BRD  BRU  ·    ·    ·  VOL-  | VOL+ |<< >/|| >>|   ·    END
          GUI  ___  SPC      |  ENT MO(4) ALT
```

**Highlights:**
- `← ↓ ↑ →` + `HOME` on a single row
- `PGDN` above `↓`, `PGUP` above `↑` — vertical extension
- Right outer column = delete cluster: `BSP` · `DEL` · `END`
- `SFT ALT CTL` on left home row — combine with arrows for word/line selection on Mac and Windows
- `_` at right index — snake_case without breaking rhythm
- Brightness, volume and media on bottom row

---

### Layer 2 — Symbols

Hold right thumb `MO(2)` to activate. Left hand free.

```
 _   !   @   (   )   %  |  *   &   ^   <   >  BSP
 ·   ·   :   {   }   =  |  #   \   /   |   $   `
 ·   ·   ·   [   ]   -  |  +   ?   ~   "   ·   ·
        GUI MO(3) SPC   |  ENT  ___ ALT
```

**Design philosophy:**
- `()` `{}` `[]` stacked vertically left cols 4–5 — one motion per bracket family
- `:` adjacent to `{}` and `=` — TypeScript/Python type annotations flow naturally
- `\ /` side by side — paths, regex, escape sequences
- `"` near `` ` `` — all string delimiters together
- `< >` top row right — generics, JSX, HTML
- `# \ / | $` right home row — shell scripting and Markdown backbone

---

### Layer 3 — Numpad + F-Keys

Hold left inner thumb `LT(3, Space)` to activate.

```
F1  F2  F3  F4  F5  F6  |  +  7  8  9  -  BSP
F7  F8  F9  F10 F11 F12  |  *  4  5  6  /   ·
 ·   ·   ·   ·   ·   ·  |  ·  1  2  3  .   ·
         GUI ___  SPC   |  ENT ___  0
```

**Highlights:**
- F1–F12 across the entire left hand
- Classic numpad layout on the right
- `0` on right thumb — most used digit at the most accessible position
- Standard keycodes `+` `*` — no numpad-specific codes

---

### Layer 4 — RGB

Accessed via `MO(4)` from Layer 1.

```
 ·    ·    ·    ·    ·  BOOT | BOOT  ·   ·   ·   ·   ·
TOGG HUE+ SAT+ VAL+  ·    · |  ·    ·   ·   ·   ·   ·
NEXT HUE- SAT- VAL-  ·    · |  ·    ·   ·   ·   ·   ·
          GUI  ___  SPC     |  ENT  ___  ALT
```

`QK_BOOT` at inner top corners of each half — accessible on both sides, requires deliberate movement.

---

## OLED Display

- **Master (left):** shows active layer name in real time
- **Slave (right):** renders the Corne logo via `oled_task_kb`

| Layer state | Display |
|---|---|
| 0 | `Layer: DVORAK` |
| 2 | `Layer: Navigate` |
| 4 | `Layer: Symbols` |
| 8 | `Layer: Numpad` |
| 16 | `Layer: RGB` |

Layer states use QMK bitmask convention (powers of 2).

---

## Dvorak vs QWERTY variant

| Feature | QWERTY | Dvorak |
|---|---|---|
| Base layout | Standard QWERTY | Standard Dvorak |
| Left pinky home | `LSFT_T(Tab)` — tap=Tab / hold=Shift | `LSFT_T(Tab)` — tap=Tab / hold=Shift |
| Top-left | `ESC` | `ESC` |
| Right pinky home | `ENT` | `ENT` |
| Bottom-right | `'` (quote) | `-` (minus) — quote is in top row |
| Right thumb inner | `MO(2)` — hold=Symbols | `MO(2)` — hold=Symbols |
| Finger travel | Standard | Reduced — home row covers ~70% of keystrokes |

---

## Cross-Platform Notes

| Action | Mac | Windows | Solution |
|---|---|---|---|
| Word navigation | Ctrl+← → | Ctrl+← → | `CTL` + arrows ✅ |
| Line start / end | Cmd+← → | Home / End | `HOME` `END` ✅ |
| Select word | Shift+Ctrl+← | Shift+Ctrl+← | `SFT`+`CTL`+arrows ✅ |
| Screenshot | Cmd+Shift+3/4/5 | `PSCR` | `PSCR` (Windows only) |
| Delete forward | Del | Del | `DEL` ✅ |
