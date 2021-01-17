.text
.align 2
.thumb
.thumb_func

hp_num_hook:
	push {lr}
	bl hp_nums_update
	pop {pc}

.align 2
