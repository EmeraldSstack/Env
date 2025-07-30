#include "envparser.h"
#include "envutils.h"
#include <stdlib.h>
#include <string.h>

// Dummy context
struct envparser_context_tag {
    void* auxil;
};

static char* lastScriptBuffer = NULL;

envparser_context_t* envparser_create(void* auxil) {
    envparser_context_t* ctx = (envparser_context_t*)malloc(sizeof(envparser_context_t));
    if (ctx) ctx->auxil = auxil;
    return ctx;
}

int envparser_parse(envparser_context_t* ctx, char** ret) {
    (void)ctx; // unused

    // Clean up previous buffer if any
    if (lastScriptBuffer) {
        free(lastScriptBuffer);
        lastScriptBuffer = NULL;
    }

    // Assume the filename was passed in via auxil (as const char*)
    const char* filename = (const char*)ctx->auxil;
    lastScriptBuffer = readScriptFile(filename);
    if (!lastScriptBuffer) return 0;

    *ret = strdup(lastScriptBuffer); // Provide output to caller
    return 1;
}

void envparser_destroy(envparser_context_t* ctx) {
    if (ctx) free(ctx);
    if (lastScriptBuffer) {
        free(lastScriptBuffer);
        lastScriptBuffer = NULL;
    }
}
