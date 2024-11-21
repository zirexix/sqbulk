#include "object.hpp"
#include "function.hpp"
#include "class.hpp"
#include "enum.hpp"
#include "table.hpp"
#include <squirrel.h>
#include <forward_list>

namespace ssq {
    Table::Table():Object() {
            
    }

    Table::Table(const Object& object):Object(object) {
        if (object.getType() != Type::TABLE) throw TypeException("bad cast", "TABLE", object.getTypeStr());
    }

    Table::Table(HSQUIRRELVM vm):Object(vm) {
        SQ_PTRS->sq_newtable(vm);
        SQ_PTRS->sq_getstackobj(vm, -1, &obj);
        SQ_PTRS->sq_addref(vm, &obj);
        SQ_PTRS->sq_pop(vm,1); // Pop table
    }

    Table::Table(const Table& other):Object(other) {
            
    }

    Table::Table(Table&& other) NOEXCEPT :Object(std::forward<Table>(other)) {
            
    }

    Function Table::findFunc(const char* name) const {
        Object object = Object::find(name);
        return Function(object);
    }

    Class Table::findClass(const char* name) const {
        Object object = Object::find(name);
        return Class(object);
    }

    Table Table::addTable(const char* name) {
        Table table(vm);
        SQ_PTRS->sq_pushobject(vm, obj);
        SQ_PTRS->sq_pushstring(vm, name, strlen(name));
        detail::push<Object>(vm, table);
        SQ_PTRS->sq_newslot(vm, -3, false);
        SQ_PTRS->sq_pop(vm,1); // pop table
        return std::move(table);
    }

    size_t Table::size() {
        SQ_PTRS->sq_pushobject(vm, obj);
        SQInteger s = SQ_PTRS->sq_getsize(vm, -1);
        SQ_PTRS->sq_pop(vm, 1);
        return static_cast<size_t>(s);
    }

    Table& Table::operator = (const Table& other){
        Object::operator = (other);
        return *this;
    }

    Table& Table::operator = (Table&& other) NOEXCEPT {
        Object::operator = (std::forward<Table>(other));
        return *this;
    }
}
