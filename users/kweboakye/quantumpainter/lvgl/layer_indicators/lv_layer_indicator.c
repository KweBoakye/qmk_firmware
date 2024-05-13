/**
 * @file lv_layer_indicator.c
 *
 */

/**
 * TODO Remove these instructions
 * Search and replace: templ -> object short name with lower case(e.g. btn, label etc)
 *                    LAYER_INDICATOR -> object short name with upper case (e.g. BTN, LABEL etc.)
 *
 * You can remove the defined() clause from the #if statement below. This exists because
 * LV_USE_LAYER_INDICATOR is not in lv_conf.h or lv_conf_layer_indicatorate.h by default.
 */

/*********************
 *      INCLUDES
 *********************/
#include "lv_layer_indicator.h" /*TODO uncomment this*/

#if defined(LV_USE_LAYER_INDICATOR) && LV_USE_LAYER_INDICATOR != 0

/*********************
 *      DEFINES
 *********************/
#define MY_CLASS &lv_layer_indicator_class

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void lv_layer_indicator_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void lv_layer_indicator_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void lv_layer_indicator_event(const lv_obj_class_t * class_p, lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/
const lv_obj_class_t lv_layer_indicator_class = {
    .constructor_cb = lv_layer_indicator_constructor,
    .destructor_cb = lv_layer_indicator_destructor,
    .event_cb = lv_layer_indicator_event,
    .width_def = LV_DPI_DEF,
    .height_def = LV_DPI_DEF,
    .instance_size = sizeof(lv_layer_indicator_t),
    .group_def = LV_OBJ_CLASS_GROUP_DEF_INHERIT,
    .editable = LV_OBJ_CLASS_EDITABLE_INHERIT,
    .base_class = &lv_layer_indicator_class,
    .name = "layer_indicator",
};

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * lv_layer_indicator_create(lv_obj_t * parent)
{

    LV_LOG_INFO("begin");
    lv_obj_t * obj = lv_obj_class_create_obj(MY_CLASS, parent);
    lv_obj_class_init_obj(obj);
    return obj;
}

/*======================
 * Add/remove functions
 *=====================*/

/*
 * New object specific "add" or "remove" functions come here
 */

/*=====================
 * Setter functions
 *====================*/

/*
 * New object specific "set" functions come here
 */

/*=====================
 * Getter functions
 *====================*/

/*
 * New object specific "get" functions come here
 */

/*=====================
 * Other functions
 *====================*/

/*
 * New object specific "other" functions come here
 */

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void lv_layer_indicator_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    lv_layer_indicator_t * layer_indicator = (lv_layer_indicator_t *)obj;
    /*Initialize the widget's data*/

    lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLLABLE);

    LV_TRACE_OBJ_CREATE("finished");
}

static void lv_layer_indicator_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    lv_layer_indicator_t * layer_indicator = (lv_layer_indicator_t *)obj;
    /*Free the widget specific data*/
}

static void lv_layer_indicator_event(const lv_obj_class_t * class_p, lv_event_t * e)
{
    LV_UNUSED(class_p);

    lv_result_t res;

    /*Call the ancestor's event handler*/
    res = LV_EVENT_base(MY_CLASS, e);
    if(res != LV_RESULT_OK) return;

    /*Add the widget specific event handling here*/
}

#else /*Enable this file at the top*/

/*This dummy typedef exists purely to silence -Wpedantic.*/
typedef int keep_pedantic_happy;
#endif