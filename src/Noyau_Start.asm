BITS 32
global _start


global read_scan_code
global wait_scan_code
global wait_key_release

extern OS_Start

%define GRUB_SIGNATURE     0x1BADB002
%define GRUB_ALIGNEMENT    0x00000001
%define GRUB_INFO_MEMOIRE  0x00000002
%define GRUB_VIDEO         0x00000004
%define GRUB_INFO_SEGMENT  0x00010000

%define GRUB_MON_FLAG GRUB_ALIGNEMENT 
%define GRUB_CHECKSUM       -(GRUB_SIGNATURE + GRUB_MON_FLAG)

_start:
	jmp Debut
;-------------------------------------------------------------------------------
        align 4
        dd GRUB_SIGNATURE
        dd GRUB_MON_FLAG
        dd GRUB_CHECKSUM
Debut:
    call  OS_Start
    cli
    hlt




read_scan_code:
    in AL,0x60
    ret

wait_scan_code:
    in AL,0x60
.repeat:
    in AL,0x64
    and AL,0x01
    jz .repeat
    in AL, 0x60
    ret

wait_key_release:
    in AL,0x60
.repeat
    in AL,0x64
    and AL,0x01
    jz .repeat
    in AL,0x60
    mov bx,ax
    and bl,0x80
    cmp bl,0x80
    jne .repeat
    ret





