#ifndef TASKS_H
#define TASKS_H

#include "../types.h"

/* Tasks system */
typedef void (*task_callback)(u8);

struct task {
	task_callback function;
	bool inuse;
	u8 prev;
	u8 next;
	u8 priority;
	u16 priv[16];
};

u8 task_add(task_callback func, u8 priority);
void task_del(u8 id);
void task_exec(void);
void taskid_set_priv_u32(u8 t_id, u8 priv_id, u32 value);
u32 task_get_priv_u32(u8 t_id, u8 priv_id);
extern struct task tasks[16];

#endif /* TASKS_H */