.text
.align 2
.thumb
.thumb_func

draw_stuff:
	mov r8, r8
	bl draw_hp_box_elements
	ldr r4, =(0x08049FC6 + 1)
	bx r4

.align 2
