SECTIONS {
         . = 0x00000000;
.text : { * (.text); }
. = 0x00010000;
.data : { * (.data); }
}
