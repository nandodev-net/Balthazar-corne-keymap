# ⌨️ Balthazar Keyboard Distributions

Custom keymaps for the **Corne (CRKBD) v3 MX Hotswap** with **Elite-Pi (RP2040)** on QMK firmware. Designed for both macOS and Windows, with ergonomic modifier placement, a navigation layer, a symbol layer built for programming, and numpad + F-keys on demand.

| Distribution | Keymap name | Base layout | Best for |
|---|---|---|---|
| [QWERTY](balthazar_qwerty/) | `balthazar_qwerty` | Standard QWERTY | Familiar layout, ergonomic mods |
| [Dvorak](balthazar_dvorak/) | `balthazar_dvorak` | Standard Dvorak | ~70% home row, reduced finger travel |

---

## Hardware

- **Keyboard:** Corne MX Hotswap v3.0.1 — 42 keys, split, ortholinear
- **MCU:** Elite-Pi (RP2040)
- **Features:** RGB Matrix · OLED · Encoder support

---

## Layer Structure (shared across both distributions)

### Layer 0 — Base (QWERTY or Dvorak)

Both layouts share the same ergonomic decisions:

- **`LSFT_T(Tab)`** on left pinky home row — tap = Tab / hold = Shift
- **`ESC`** top-left, **`ENT`** right pinky home row, **`BSP`** top-right
- **`Ctrl`** bottom-left — no more chronic stretch
- Left thumb: `GUI` · `MO(1)` Navigate · `LT(3,SPC)` Numpad
- Right thumb: `SPC` · `MO(2)` Symbols · `Alt`

```
QWERTY:
ESC   Q   W   E   R   T  |  Y   U   I   O   P   BSP
TAB/SFT A S   D   F   G  |  H   J   K   L   ;   ENT
CTL   Z   X   C   V   B  |  N   M   ,   .   /   '
        GUI MO(1) LT(3,SPC) | SPC MO(2) ALT

Dvorak:
ESC   '   ,   .   P   Y  |  F   G   C   R   L   BSP
TAB/SFT A O   E   U   I  |  D   H   T   N   S   ENT
CTL   ;   Q   J   K   X  |  B   M   W   V   Z   -
          GUI MO(1) LT(3,SPC) | SPC MO(2) ALT
```

---

### Layer 1 — Navigate `MO(1)`

Hold left middle thumb to activate.

```
TAB   ·   ·    ·    ·    ·   |   _   ·  PGDN PGUP PSCR  BSP
 ·    ·  SFT  ALT  CTL   ·   | HOME  ←    ↓    ↑    →   DEL
BRD  BRU  ·    ·    ·  VOL-  | VOL+ |<< >/|| >>|   ·    END
          GUI  ___  SPC      |  ENT MO(4) ALT
```

- Arrows + Home on a single row · PgDn/PgUp above ↓/↑
- `SFT ALT CTL` on left home row — word/line selection on Mac and Windows
- Right column: `BSP · DEL · END` delete cluster
- `_` at right index — snake_case without breaking rhythm
- Brightness, volume, media on bottom row

---

### Layer 2 — Symbols `MO(2)`

Hold right thumb to activate.

```
 _   !   @   (   )   %  |  *   &   ^   <   >  BSP
 ·   ·   :   {   }   =  |  #   \   /   |   $   `
 ·   ·   ·   [   ]   -  |  +   ?   ~   "   ·   ·
        GUI MO(3) SPC   |  ENT  ___ ALT
```

- `()` `{}` `[]` stacked vertically — one motion per bracket family
- `\ /` side by side — paths, regex, escapes
- `< >` top right — generics, JSX, HTML
- `# \ / | $` right home row — shell and Markdown backbone

---

### Layer 3 — Numpad + F-Keys `LT(3,SPC)`

Hold left inner thumb to activate.

```
F1  F2  F3  F4  F5  F6  |  +  7  8  9  -  BSP
F7  F8  F9  F10 F11 F12  |  *  4  5  6  /   ·
 ·   ·   ·   ·   ·   ·  |  ·  1  2  3  .   ·
         GUI ___  SPC   |  ENT ___  0
```

- F1–F12 across entire left hand · Classic numpad on right · `0` on thumb

---

### Layer 4 — RGB `MO(4)`

Accessed via `MO(4)` from Navigate (Layer 1).

```
 ·    ·    ·    ·    ·  BOOT | BOOT  ·   ·   ·   ·   ·
TOGG HUE+ SAT+ VAL+  ·    · |  ·    ·   ·   ·   ·   ·
NEXT HUE- SAT- VAL-  ·    · |  ·    ·   ·   ·   ·   ·
          GUI  ___  SPC     |  ENT  ___  ALT
```

`QK_BOOT` at inner top corners — requires deliberate movement.

---

## Compiling & Flashing

```bash
# QWERTY
qmk compile -kb crkbd/rev1 -km balthazar_qwerty -e CONVERT_TO=elite_pi

# Dvorak
qmk compile -kb crkbd/rev1 -km balthazar_dvorak -e CONVERT_TO=elite_pi
```

1. Disconnect the TRRS cable
2. Connect one half via USB
3. Double-press the reset button — `RPI-RP2` drive appears
4. Copy the `.uf2` from `qmk_firmware/.build/` to the drive
5. Repeat for the other half · Reconnect TRRS

---

## Tap-Hold Notes

`LSFT_T(Tab)` uses QMK mod-tap. If you type fast, tune `TAPPING_TERM` in `config.h`:

```c
#define TAPPING_TERM 150  // ms — default is 200
```
