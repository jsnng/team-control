%module world_model

%{
#define SWIG_FILE_WITH_INIT
#include <optional>
#include <queue>
#include <ranges>
#include "World.h"
%}
%include "World.h"