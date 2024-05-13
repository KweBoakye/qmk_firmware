/**
 * @file lv_layer_indicator.h
 *
 */


#ifndef LV_LAYER_INDICATOR_H
#define LV_LAYER_INDICATOR_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "lvgl/lv_conf_internal.h"

#if LV_USE_LAYER_INDICATOR != 0

#include "../core/lv_obj.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
/*Data of layer_indicator*/
typedef struct {
     lv_obj_t obj;
    /*New data for this type*/
} lv_layer_indicator_t;

LV_ATTRIBUTE_EXTERN_DATA extern const lv_obj_class_t lv_layer_indicator_class;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create a layer_indicator object
 * @param parent    pointer to an object, it will be the parent of the new layer_indicator
 * @return          pointer to the created layer_indicator object
 */
lv_obj_t * lv_layer_indicator_create(lv_obj_t * parent);

/*======================
 * Add/remove functions
 *=====================*/

/*=====================
 * Setter functions
 *====================*/

/*=====================
 * Getter functions
 *====================*/

/*=====================
 * Other functions
 *====================*/

/**********************
 *      MACROS
 **********************/

#endif /*LV_USE_LAYER_INDICATOR*/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LV_LAYER_INDICATOR_H*/