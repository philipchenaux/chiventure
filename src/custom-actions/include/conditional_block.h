/* 
 * Functions and structs to be used in conditional_block_t implementation
 */

#ifndef INCLUDE_CONDITIONAL_BLOCK_H
#define INCLUDE_CONDITIONAL_BLOCK_H

#include <stdlib.h>
#include <stdio.h>
#include "game-state/item.h"
#include "ast_block.h"

/* An enumeration type for a conditional block */
typedef enum conditional_type {
    EQ,
    LTGT,
    LTEGTE,
    IN
} conditional_type_t;

/* A block that returns true or false, and contains an operator and two attributes */
typedef struct conditional_block {
    conditional_type_t conditional_type;
    attribute_t* left;
    attribute_t* right;
} conditional_block_t;

/* 
 * Allocates a conditional block in the heap. 
 * 
 * Parameters: 
 * - pointer to a "left" attribute
 * - pointer to a "right" attribute 
 * - enum representing the conditional type 
 * 
 * Returns: 
 * - A conditional block. 
 */
conditional_block_t* conditional_block_new(conditional_type_t conditional_type, 
attribute_t* left, attribute_t* right);

/* 
 * Allocates an AST type conditional block in the heap. 
 * 
 * Parameters: 
 * - pointer to a "left" attribute
 * - pointer to a "right" attribute 
 * - enum representing the conditional type 
 * 
 * Returns: 
 * - A conditional block. 
 */
AST_block_t* AST_conditional_block_new(conditional_type_t conditional_type, 
attribute_t* left, attribute_t* right);

/* 
 * Initializes a conditional block. 
 * 
 * Parameters: 
 * - conditional block. Must point to already allocated memory.  
 * - pointer to a "left" attribute 
 * - pointer to a "right" attribute  
 * - enum representing the conditional type    
 * 
 * Returns: 
 * - SUCCESS if success, FAILURE if error occurs
 */
int conditional_block_init(conditional_block_t *conditional, conditional_type_t 
conditional_type, attribute_t* left, attribute_t* right);

/* 
 * Frees a conditional block. 
 * 
 * Parameters: 
 * - conditional block. Must point to a conditional block allocated with conditional_block_new. 
 * 
 * Returns: 
 * - Always returns 0. 
 */
int conditional_block_free(conditional_block_t *conditional);

#endif /* INCLUDE_CONDITIONAL_BLOCK_H */
