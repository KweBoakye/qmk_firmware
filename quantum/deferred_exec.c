// Copyright 2021 Nick Brassel (@tzarc)
// SPDX-License-Identifier: GPL-2.0-or-later

#include <stddef.h>
#include <timer.h>
#include <deferred_exec.h>

#ifndef MAX_DEFERRED_EXECUTORS
#    define MAX_DEFERRED_EXECUTORS 8
#endif

<<<<<<< HEAD
//------------------------------------
// Helpers
//

static deferred_token current_token = 0;

static inline bool token_can_be_used(deferred_executor_t *table, size_t table_count, deferred_token token) {
    if (token == INVALID_DEFERRED_TOKEN) {
        return false;
    }
    for (int i = 0; i < table_count; ++i) {
        if (table[i].token == token) {
=======
typedef struct deferred_executor_t {
    deferred_token         token;
    uint32_t               trigger_time;
    deferred_exec_callback callback;
    void *                 cb_arg;
} deferred_executor_t;

static deferred_token      current_token                     = 0;
static uint32_t            last_deferred_exec_check          = 0;
static deferred_executor_t executors[MAX_DEFERRED_EXECUTORS] = {0};

static inline bool token_can_be_used(deferred_token token) {
    if (token == INVALID_DEFERRED_TOKEN) {
        return false;
    }
    for (int i = 0; i < MAX_DEFERRED_EXECUTORS; ++i) {
        if (executors[i].token == token) {
>>>>>>> c0de397925 (merge bedore pointerwork)
            return false;
        }
    }
    return true;
}

<<<<<<< HEAD
static inline deferred_token allocate_token(deferred_executor_t *table, size_t table_count) {
    deferred_token first = ++current_token;
    while (!token_can_be_used(table, table_count, current_token)) {
=======
static inline deferred_token allocate_token(void) {
    deferred_token first = ++current_token;
    while (!token_can_be_used(current_token)) {
>>>>>>> c0de397925 (merge bedore pointerwork)
        ++current_token;
        if (current_token == first) {
            // If we've looped back around to the first, everything is already allocated (yikes!). Need to exit with a failure.
            return INVALID_DEFERRED_TOKEN;
        }
    }
    return current_token;
}

<<<<<<< HEAD
//------------------------------------
// Advanced API: used when a custom-allocated table is used, primarily for core code.
//

deferred_token defer_exec_advanced(deferred_executor_t *table, size_t table_count, uint32_t delay_ms, deferred_exec_callback callback, void *cb_arg) {
    // Ignore queueing if the table isn't valid, it's a zero-time delay, or the token is not valid
    if (!table || table_count == 0 || delay_ms == 0 || !callback) {
=======
deferred_token defer_exec(uint32_t delay_ms, deferred_exec_callback callback, void *cb_arg) {
    // Ignore queueing if it's a zero-time delay, or invalid callback
    if (delay_ms == 0 || !callback) {
>>>>>>> c0de397925 (merge bedore pointerwork)
        return INVALID_DEFERRED_TOKEN;
    }

    // Find an unused slot and claim it
<<<<<<< HEAD
    for (int i = 0; i < table_count; ++i) {
        deferred_executor_t *entry = &table[i];
        if (entry->token == INVALID_DEFERRED_TOKEN) {
            // Work out the new token value, dropping out if none were available
            deferred_token token = allocate_token(table, table_count);
=======
    for (int i = 0; i < MAX_DEFERRED_EXECUTORS; ++i) {
        deferred_executor_t *entry = &executors[i];
        if (entry->token == INVALID_DEFERRED_TOKEN) {
            // Work out the new token value, dropping out if none were available
            deferred_token token = allocate_token();
>>>>>>> c0de397925 (merge bedore pointerwork)
            if (token == INVALID_DEFERRED_TOKEN) {
                return false;
            }

            // Set up the executor table entry
            entry->token        = current_token;
            entry->trigger_time = timer_read32() + delay_ms;
            entry->callback     = callback;
            entry->cb_arg       = cb_arg;
            return current_token;
        }
    }

    // None available
    return INVALID_DEFERRED_TOKEN;
}

<<<<<<< HEAD
bool extend_deferred_exec_advanced(deferred_executor_t *table, size_t table_count, deferred_token token, uint32_t delay_ms) {
    // Ignore queueing if the table isn't valid, it's a zero-time delay, or the token is not valid
    if (!table || table_count == 0 || delay_ms == 0 || token == INVALID_DEFERRED_TOKEN) {
=======
bool extend_deferred_exec(deferred_token token, uint32_t delay_ms) {
    // Ignore queueing if it's a zero-time delay, or the token is not valid
    if (delay_ms == 0 || token == INVALID_DEFERRED_TOKEN) {
>>>>>>> c0de397925 (merge bedore pointerwork)
        return false;
    }

    // Find the entry corresponding to the token
<<<<<<< HEAD
    for (int i = 0; i < table_count; ++i) {
        deferred_executor_t *entry = &table[i];
=======
    for (int i = 0; i < MAX_DEFERRED_EXECUTORS; ++i) {
        deferred_executor_t *entry = &executors[i];
>>>>>>> c0de397925 (merge bedore pointerwork)
        if (entry->token == token) {
            // Found it, extend the delay
            entry->trigger_time = timer_read32() + delay_ms;
            return true;
        }
    }

    // Not found
    return false;
}

<<<<<<< HEAD
bool cancel_deferred_exec_advanced(deferred_executor_t *table, size_t table_count, deferred_token token) {
    // Ignore request if the table/token are not valid
    if (!table || table_count == 0 || token == INVALID_DEFERRED_TOKEN) {
=======
bool cancel_deferred_exec(deferred_token token) {
    // Ignore request if the token is not valid
    if (token == INVALID_DEFERRED_TOKEN) {
>>>>>>> c0de397925 (merge bedore pointerwork)
        return false;
    }

    // Find the entry corresponding to the token
<<<<<<< HEAD
    for (int i = 0; i < table_count; ++i) {
        deferred_executor_t *entry = &table[i];
=======
    for (int i = 0; i < MAX_DEFERRED_EXECUTORS; ++i) {
        deferred_executor_t *entry = &executors[i];
>>>>>>> c0de397925 (merge bedore pointerwork)
        if (entry->token == token) {
            // Found it, cancel and clear the table entry
            entry->token        = INVALID_DEFERRED_TOKEN;
            entry->trigger_time = 0;
            entry->callback     = NULL;
            entry->cb_arg       = NULL;
            return true;
        }
    }

    // Not found
    return false;
}

<<<<<<< HEAD
void deferred_exec_advanced_task(deferred_executor_t *table, size_t table_count, uint32_t *last_execution_time) {
    uint32_t now = timer_read32();

    // Throttle only once per millisecond
    if (((int32_t)TIMER_DIFF_32(now, (*last_execution_time))) > 0) {
        *last_execution_time = now;

        // Run through each of the executors
        for (int i = 0; i < table_count; ++i) {
            deferred_executor_t *entry = &table[i];
=======
void deferred_exec_task(void) {
    uint32_t now = timer_read32();

    // Throttle only once per millisecond
    if (((int32_t)TIMER_DIFF_32(now, last_deferred_exec_check)) > 0) {
        last_deferred_exec_check = now;

        // Run through each of the executors
        for (int i = 0; i < MAX_DEFERRED_EXECUTORS; ++i) {
            deferred_executor_t *entry = &executors[i];
>>>>>>> c0de397925 (merge bedore pointerwork)

            // Check if we're supposed to execute this entry
            if (entry->token != INVALID_DEFERRED_TOKEN && ((int32_t)TIMER_DIFF_32(entry->trigger_time, now)) <= 0) {
                // Invoke the callback and work work out if we should be requeued
                uint32_t delay_ms = entry->callback(entry->trigger_time, entry->cb_arg);

                // Update the trigger time if we have to repeat, otherwise clear it out
                if (delay_ms > 0) {
                    // Intentionally add just the delay to the existing trigger time -- this ensures the next
                    // invocation is with respect to the previous trigger, rather than when it got to execution. Under
                    // normal circumstances this won't cause issue, but if another executor is invoked that takes a
                    // considerable length of time, then this ensures best-effort timing between invocations.
                    entry->trigger_time += delay_ms;
                } else {
                    // If it was zero, then the callback is cancelling repeated execution. Free up the slot.
                    entry->token        = INVALID_DEFERRED_TOKEN;
                    entry->trigger_time = 0;
                    entry->callback     = NULL;
                    entry->cb_arg       = NULL;
                }
            }
        }
    }
}
<<<<<<< HEAD

//------------------------------------
// Basic API: used by user-mode code, guaranteed to not collide with core deferred execution
//

static uint32_t            last_deferred_exec_check                = 0;
static deferred_executor_t basic_executors[MAX_DEFERRED_EXECUTORS] = {0};

deferred_token defer_exec(uint32_t delay_ms, deferred_exec_callback callback, void *cb_arg) {
    return defer_exec_advanced(basic_executors, MAX_DEFERRED_EXECUTORS, delay_ms, callback, cb_arg);
}
bool extend_deferred_exec(deferred_token token, uint32_t delay_ms) {
    return extend_deferred_exec_advanced(basic_executors, MAX_DEFERRED_EXECUTORS, token, delay_ms);
}
bool cancel_deferred_exec(deferred_token token) {
    return cancel_deferred_exec_advanced(basic_executors, MAX_DEFERRED_EXECUTORS, token);
}
void deferred_exec_task(void) {
    deferred_exec_advanced_task(basic_executors, MAX_DEFERRED_EXECUTORS, &last_deferred_exec_check);
}
=======
>>>>>>> c0de397925 (merge bedore pointerwork)
