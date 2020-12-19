# kbd.tbl.ru -- RU-101 keyboard layout

# To use this mapping, copy this file to
#   /etc/kbd.tbl
# and press  CTRL+ALT+SPACE  to reload the mapping dynamically.


# Syntax
# ------
# This file's structure is very simple and rigid. It must contain
# either *exactly* 5*96 or *exactly* 6*96 hexadecimal entries, 
# separated by whitespace, newlines, or commas. If it contains 5*96 
# entries, left and right Alt keys will both be treated as regular
# Alt keys. If the file has 6*96 entries, the right Alt key will be
# treated as an AltGr key, and the last 96 entries must define key
# codes for each key with AltGr pressed.
# Entries must be no longer than 4 hex digits (16 bits) each.
# Comments must start with a '#'; they extend to the end of the line.


# Semantics
# ---------
# Each run of 96 entries defines the semantics of up to 96 different 
# keys under certain conditions:
# 
# Entries  Define semantics for keys...
#  000-095  Without any modifiers
#  096-191  With SHIFT pressed
#  192-287  With CTRL pressed
#  288-383  With ALT pressed
#  384-479  With CTRL+ALT pressed
# [480-575  With ALT-GR (right ALT) pressed]
# 
# The 96 entries in a run are indexed by keyboard scan codes.
# You'll need to know those scan codes in order to make up your own
# keyboard definition. Given below is the scancode/symbol-mapping
# for a US-101 keyboard:
# 
#   0     1     2     3     4     5     6     7    8     9     A     B     C     D     E     F
#     ,  Esc,  '1',  '2',  '3',  '4',  '5',  '6'  '7',  '8',  '9',  '0',  '-',  '=',  Rub,  Tab  ; 00
#  'q',  'w',  'e',  'r',  't',  'y',  'u',  'i'  'o',  'p',  '[',  ']',  Ent,  Ctl,  'a',  's'  ; 10
#  'd',  'f',  'g',  'h',  'j',  'k',  'l',  ';'  ''',  '`',  Shf,  '\',  'z',  'x',  'c',  'v'  ; 20
#  'b',  'n',  'm',  ',',  '.',  '/',  Rsh,  '*'  Alt,   SP,  Cap,   F1,   F2,   F3,   F4,   F5  ; 30
#   F6,   F7,   F8,   F9,  F10,  Num,  Scr,  Hom   Up,  PgU,   K-,  Lft,   K5,  Rig,   K+,  End  ; 40
#  Dwn,  PgD,  Ins,  Del,     ,     ,     ,  F11  F12,     ,     ,     ,     ,     ,     ,       ; 50
# 
# For every scan code, two bytes of data are given by the entries.
# The high byte defines a number of flags for the key (see below), 
# while the low byte usually carries the actual data to be given 
# to the "user" when the key is pressed. Only for shift, lock, and
# special keys, the low byte will carry additional, function-dependant
# information (see below, too).


# Entries' high bits
# ------------------
#
#  00  - Data Key
#  01  - Function Key
#  02  - Shift key
#        0201 = Shift
#        0202 = Ctl
#        0204 = Alt
#        0208 = Rshift
#  04  - Numlock dependant
#  08  - Lock Key
#        0801 = ScrollLock
#        0802 = NumLock
#        0804 = CapsLock
#  10  - Dead Key
#  20  - Capslock dependant
#  40  - Special
#        4001 = reboot (ctl-alt-del)
#        4002 = debug  (ctl-alt-esc)
#        4003 = con+   (ctl-alt-plus/CR)
#        4004 = con-   (ctl-alt-minus)
#        4005 = con1   (ctl-alt-1)
#        4006 = con2   (ctl-alt-2)
#        ...
#        400C = con8   (ctl-alt-8)
#        400D = con9   (ctl-alt-9)
#        400E = con10  (ctl-alt-0)
#        400F = size+  (ctl-alt->)
#        4010 = size-  (ctl-alt-<)
#        4011 = help   (ctl-alt-?)
#        4012 = break  (ctl-Break)
#        4013 = hangup (ctl-alt-End)
# 
#        4020 = prtsc  (ctl-alt-PRTSC)
#        4021 = hot1   (ctl-alt-F1)
#        4022 = hot2   (ctl-alt-F2)
#        ...
#        402B = reload (ctl-alt-space)
#
#  80  - Invalid key
#
# ================================================================================

#	Base codes
	8000,001B,0031,0032,0033,0034,0035,0036,	0037,0038,0039,0030,002D,003D,007F,0009,
	20A9,20E6,20E3,20AA,20A5,20AD,20A3,20E8,	20E9,20A7,20E5,20EA,000D,0202,20E4,20EB,
	20A2,20A0,20AF,20E0,20AE,20AB,20A4,20A6,	20ED,20F1,0201,005C,20EF,20E7,20E1,20AC,
	20A8,20E2,20EC,20A1,20EE,002E,0208,002A,	0204,0020,0804,0181,0182,0183,0184,0185,
	0186,0187,0188,0189,018A,0802,0801,05A0,	05A1,05A2,05A3,05A4,05A5,05A6,05A7,05A8,
	05A9,05AA,05AB,05AC,8000,8000,8000,01AE,	01AF,8000,8000,8000,8000,8000,8000,8000,

#	Shift codes
	8000,001B,0021,0022,00FC,003B,0025,003A,	003F,002A,0028,0029,005F,002B,01FC,0180,
	2089,2096,2093,208A,2085,208D,2083,2098,	2099,2087,2095,209A,01E0,0202,2094,209B,
	2082,2080,208F,2090,208E,208B,2084,2086,	209D,20F0,0201,002F,209F,2097,2091,208C,
	2088,2092,209C,2081,209E,002C,0208,01AD,	0204,0020,8000,018B,018C,018D,018E,018F,
	0190,0191,0192,0193,0194,8000,8000,0437,	0438,0439,042D,0434,0435,0436,042B,0431,
	0432,0433,0430,042E,8000,8000,8000,01DB,	01DC,8000,8000,8000,8000,8000,8000,8000,

#	Cntl codes
	8000,001B,8000,0000,8000,8000,8000,001E,	8000,8000,8000,8000,001F,8000,01DE,019F,
	0011,0017,0005,0012,0014,0019,0015,0009,	000F,0010,001B,001D,01D0,0202,0001,0013,
	0004,0006,0007,0008,000A,000B,000C,8000,	1027,8000,0201,001C,001A,0018,0003,0016,
	0002,000E,000D,8000,8000,8000,0208,01BD,	0204,0020,8000,0195,0196,0197,0198,0199,
	019A,019B,019C,019D,019E,8000,4012,01B0,	01B1,01B2,01B3,01B4,01B5,01B6,01B7,01B8,
	01B9,01BA,01BB,01BC,8000,8000,8000,01BE,	01BF,8000,8000,8000,8000,8000,8000,8000,

#	Alt codes
	8000,001B,8000,8000,8000,8000,8000,8000,	8000,8000,8000,8000,8000,8000,01DF,8000,
	01F1,01F7,01E5,01F2,01F4,01F9,01F5,01E9,	01EF,01F0,8000,8000,01FB,0202,01E1,01F3,
	01E4,01E6,01E7,01E8,01EA,01EB,01EC,8000,	8000,8000,0201,8000,01FA,01F8,01E3,01F6,
	01E2,01EE,01ED,8000,8000,8000,0208,01CD,	0204,8000,8000,01D1,01D2,01D3,01D4,01D5,
	01D6,01D7,01D8,01D9,01DA,8000,8000,01C0,	01C1,01C2,01C3,01C4,01C5,01C6,01C7,01C8,
	01C9,01CA,01CB,01CC,01DD,8000,8000,01CE,	01CF,8000,8000,8000,8000,8000,8000,8000,

#	Ctl-Alt codes
	8000,4002,4005,4006,4007,4008,4009,400A,	400B,400C,400D,400E,8000,8000,4004,8000,
	8000,8000,8000,8000,8000,8000,8000,8000,	8000,8000,8000,8000,4003,0202,8000,8000,
	8000,8000,8000,8000,8000,8000,8000,8000,	8000,8000,0201,8000,8000,8000,8000,8000,
	8000,8000,8000,4010,400F,4011,0208,4020,	0204,402B,8000,4021,4022,4023,4024,4025,
	4026,4027,4028,4029,402A,8000,8000,8000,	8000,8000,4004,8000,8000,8000,4003,8000,
	8000,8000,8000,4001,4020,8000,8000,8000,	8000,8000,8000,8000,8000,8000,8000,8000,

# No AltGr on RU-101
