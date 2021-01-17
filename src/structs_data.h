#ifndef WRAM_STRUCTS_DATA_H
#define WRAM_STRUCTS_DATA_H

 /* sav2 structure */
 struct saveblock_trainerdata {
	struct sav2 *sav2;
};

struct sav2 {
	char name[8];
	u8 gender;
	u8 padding;
	u16 trainer_id;
	u16 secret_id;
	u16 hours;
	u8 minutes;
	u8 seconds;
	u8 frames;
	u8 options_button_style;
	u8 options_text_speed;
	u8 options_battle_style[7];
	u32 field_1C;
	u8 field_20[8];
	u8 pokemon_flags_3[52];
	u8 pokemon_flags_4[52];
	u8 field_90[1044];
	u8 fourCharacters[4];
	u8 field_4A8[1008];
	u8 mapdata[1672];
	u32 bag_item_quantity_xor_value;
	u8 field_F24[127];
	u8 last_byte_in_sav2;
};
extern struct saveblock_trainerdata saveblock2;

/* vars */

struct temp_vars {
	// Only 0x8000s here
	u16 var_8000;
	u16 var_8001;
	u16 var_8002;
	u16 var_8003;
	u16 var_8004;
	u16 var_8005;
	u16 var_8006;
	u16 var_8007;
	u16 var_8008;
	u16 var_8009;
	u16 var_800A;
	u16 var_800B;
	u16 var_800D;
	u16 var_800F;
	u16 var_800C;
	u16 var_8010;
	u16 var_8011;
};
extern struct temp_vars temp_vars;

 struct pokemon {
	u32 PID;
	u32 OTID;
	char name[10];
	u16 language;
	u8 OT_name[7];
	u8 markings;
	u16 checksum;
	u16 padding_maybe;
	u8 data[48];
	u32 ailment;
	u8 level;
	u8 pokerus;
	u16 current_hp;
	u16 total_hp;
	u16 attack;
	u16 defense;
	u16 speed;
	u16 sp_attack;
	u16 sp_defense;
};

extern struct pokemon player_party[6];
extern struct pokemon opponent_party[6];

struct base_stat {
	u8 hp;
	u8 atk;
	u8 def;
	u8 spd;
	u8 spatk;
	u8 spdef;
	u8 type1;
	u8 type2;
	u8 catch_rate;
	u8 exp_yield;
	u16 ev_yield;
	u16 item1;
	u16 item2;
	u8 gender_ratio;
	u8 steps_to_hatch;
	u8 base_friendship;
	u8 exp_curve;
	u8 egg_group1;
	u8 egg_group2;
	u8 ability_1;
	u8 ability_2;
	u8 safari_zone_flee_rate;
	u8 color;
	u16 padding;
};

extern struct base_stat base_stats[450];

extern u32 exp_curve[404 * 6];

/* HP bar battle structure */
struct battle_data_something {
	u8 *unk1;
	u8 *unk2;
	u8 *unk3;
	struct hp_bar_data *hpdata[4];
};

struct hp_bar_data {
	u8 obj_id;
	u8 padding[3];
	u32 max_hp;
	u32 c_hp;
	u32 last_turn_dmg_taken;
	u32 unk2;
	
};

extern struct battle_data_something *dp_11;

/* Exp related */



u32 get_attr(struct pokemon *pkmn, u8 arg);
void get_attr2(struct pokemon *pkmn, u8 arg, char *);
void set_attr(struct pokemon *pkmn, u8 index, void *to_set);

#endif /* WRAM_STRUCTS_DATA_H */
