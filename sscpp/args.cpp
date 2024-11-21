#include "object.hpp"
#include "args.hpp"
#include "class.hpp"
#include "instance.hpp"
#include "table.hpp"
#include "function.hpp"
#include "enum.hpp"
#include "array.hpp"
#include <squirrel.h>

namespace ssq {
    namespace detail {
        void pushRaw(HSQUIRRELVM vm, const Object& value) {
            SQ_PTRS->sq_pushobject(vm, value.getRaw());
        }
        void pushRaw(HSQUIRRELVM vm, const Class& value) {
            SQ_PTRS->sq_pushobject(vm, value.getRaw());
        }
        void pushRaw(HSQUIRRELVM vm, const Instance& value) {
            SQ_PTRS->sq_pushobject(vm, value.getRaw());
        }
        void pushRaw(HSQUIRRELVM vm, const Table& value) {
            SQ_PTRS->sq_pushobject(vm, value.getRaw());
        }
        void pushRaw(HSQUIRRELVM vm, const Function& value) {
            SQ_PTRS->sq_pushobject(vm, value.getRaw());
        }
        void pushRaw(HSQUIRRELVM vm, const Enum& value) {
            SQ_PTRS->sq_pushobject(vm, value.getRaw());
        }
        void pushRaw(HSQUIRRELVM vm, const Array& value) {
            SQ_PTRS->sq_pushobject(vm, value.getRaw());
        }
        void pushRaw(HSQUIRRELVM vm, const SqWeakRef& value) {
            SQ_PTRS->sq_pushobject(vm, value.getRaw());
        }
    }
}
