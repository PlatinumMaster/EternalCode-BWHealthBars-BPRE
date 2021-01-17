#ifndef ENGINE_OBJECTS_H
#define ENGINE_OBJECTS_H



struct object;
typedef void (*object_callback)(struct object*);


typedef struct frame {
	u16 data;
	u16 duration;
} frame;

struct rotscale_frame {
	u16 scale_delta_x;
	u16 scale_delta_y;
	u8 rotation_delta;
	u8 duration;
	u16 field_6;
};

struct attri0 {
	u8 y;
	u8 rot_scale_flag : 1;
	u8 doublesize_disable_flag : 1; // if rotscale 0, disable obj. Else double size
	u8 obj_mode : 2; // 0 normal, 1 semi transparent, 2 obj window, 3 prohibited
	u8 obj_mosaic : 1;
	u8 color_mode : 1; // 16 or 256
	u8 obj_shape : 2; // 0=Square,1=Horizontal,2=Vertical
};

struct attri1 {
	u16 x : 9;
	u16 rot_scale : 3;
	u16 h_flip : 1;
	u16 v_flip : 1;
	u16 obj_size : 2;
};

struct attri2{
	u16 tile_num : 10;
	u16 priority : 2;
	u16 pal_num : 4;
};

struct sprite {
	struct attri0 attr0;
	struct attri1 attr1;
	struct attri2 attr2;
	u16 rotscale;
};

struct resource {
	u8 *graphics;
	u16 size;
	u16 tag;
};

struct objtemplate {
	u16 tiles_tag;
	u16 pal_tag;
	struct sprite *oam;
	struct frame **animation;
	struct resource *graphics;
	struct rotscale_frame *rotscale;
	object_callback callback;
};

struct object {
	struct sprite final_oam;
	struct frame **animation_table;
	u8 *gfx_table;
	struct rotscale_frame **rotscale_table;
	struct objtemplate *template;
	u32 field18;
	object_callback callback;
	u16 x;
	u16 y;
	u16 x2;
	u16 y2;
	u8 x_centre;
	//u8 y_centre;
	u8 anim_number;
	u8 anim_frame;
	u8 anim_delay;
	u8 counter;
	u16 private[8];
	u8 bitfield2;
	u8 bitfield;
	u16 anim_data_offset;
	u8 field42;
	u8 field43;
};


struct tagged_pal {
	u8 *pal_ptr;
	u16 pal_tag;
	u16 padding;
};

extern struct object objects[64];

u8 *obj_ids_to_display;
struct sprite * poke_oam_battle;
struct frame ** anim_poke;
struct rotscale_frame **rotscale_empty;
object_callback oac_nullsub;
u8 template_instanciate_forward_search(struct objtemplate *, u8, u8, u8);
u8 template_instanciate_reverse_search(struct objtemplate *, u8, u8, u8);
void obj_delete(struct object *);
void obj_delete_and_free_tiles(struct object *);
void gpu_tile_obj_alloc_tag_and_upload(struct resource *);
void gpu_pal_obj_alloc_tag_and_apply(struct tagged_pal *);

u8 obj_id_from_obj(struct object *obj) {
	u32 pointer = (u8 *)obj - (u8 *)objects;
	return ((u32)pointer / 0x44);
}


#endif /* ENGINE_OBJECTS_H */
