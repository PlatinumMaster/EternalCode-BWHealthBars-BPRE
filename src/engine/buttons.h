#ifndef BUTTONS_H
#define BUTTONS_H

#include "../types.h"
#include "objects.h"

/* Button definitions */
#define KEYA            1
#define KEYB            2
#define KEYSELECT       4
#define KEYSTART        8
#define KEYRIGHT        16
#define KEYLEFT         32
#define KEYUP           64
#define KEYDOWN         128
#define KEYR            256
#define KEYL            512


/* Super state */
typedef void (*super_callback)(void);

struct super {
	super_callback callback1;
	super_callback callback2;
	super_callback callback2backup;
	super_callback callback_vblank;
	super_callback callback_hblank;
	u32 field_14;
	u32 field_18;
	u32 bit_to_wait_for;
	u32 *ptr_vblank_counter;
	u32 field_24;
	u16 buttons_held;
	u16 buttons_new;
	u16 buttons_held_remapped;
	u16 buttons_new_remapped;
	u16 buttons_new_and_key_repeat;
	u32 keypad_countdown;
	u32 unused_padding;
	struct sprite sprites[128];
	u8 multipurpose_state_tracker;
	u8 gpu_sprites_upload_skip;
 };

extern struct super superstate;

#endif /* BUTTONS_H */