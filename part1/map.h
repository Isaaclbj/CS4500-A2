// lang:CwC
/*
* Authors: Ryan Heminway (heminway.r@husky.neu.edu), David Tandetnik 
* CS4500 A1 Part 2 (Map definition)
*/
#pragma once

#include <stdlib.h>
#include "object.h"

/*
* Map represents a collection of (key, value) pairs. Each key is unique
* and is associated with a single value.
*/
class Map : public Object {
   public:

    size_t used;
    size_t cap;
    Object **keys;
    Object **vals;

    Map() 
    {
        used = 0;
        cap = 10;
        keys = new Object*[cap]();
        vals = new Object*[cap]();
    }

    ~Map() 
    {
        delete[] keys;
        delete[] vals;
    }

    // Returns true if the given key is associated with a value, else false
    // Always false if key == nullptr
    bool has_key(Object* key) 
    {
        if(!key)
        {
            return false;
        }
        for(int ii = 0; ii < used; ii ++)
        {
            if(keys[ii] && key->equals(keys[ii]))
            {
                return true;
            }
        }
        return false;
    }

    // Returns the value associated with given key, or nullptr if no value
    // Expects user to cast response to get subtypes
    Object* get(Object* key) 
    {
        if(!key)
        {
            return NULL;
        }

        for(int ii = 0; ii < used; ii ++)
        {
            if(keys[ii] && key->equals(keys[ii]))
            {
                return vals[ii];
            }
        }
        return NULL;
    }

    // Associates the given key with the given value. Any existing value
    // associated with this key is overwritten
    // Does nothing if key or value == nullptr
    void put(Object* key, Object* value) 
    {
        if(!value || !key)
        {
            return;
        }
        for(int ii = 0; ii < cap; ii++)
        {
            if(keys[ii] && keys[ii]->equals(key))
            {
                vals[ii] = value;
                return;
            }
        }

        used ++;
        if(used > cap)
        {
            cap *= 2;
            Object** pp = new Object*[cap];
            Object** tt = new Object*[cap];
            memcpy(pp, keys, sizeof(Object*) * (used - 1));
            memcpy(tt, vals, sizeof(Object*) * (used - 1));
            delete[] vals;
            delete[] keys;
            keys = pp;
            vals = tt;
            keys[used - 1] = key;
            vals[used - 1] = value;
            return;
        }

        for(int ii = 0; ii < cap; ii ++)
        {
            if(!keys[ii])
            {
                keys[ii] = key;
                vals[ii] = value;
                return;
            }
        }
    }

    // Removes and returns the value associated with the given key.
    // Returns nullptr if no value exists for given key.
    Object* remove(Object* key) 
    {
        if(!key)
        {
            return NULL;
        }
        for(int ii = 0; ii < cap; ii ++)
        {
            if(keys[ii] && keys[ii]->equals(key))
            {
                Object *ret = vals[ii];
                vals[ii] = NULL;
                keys[ii] = NULL;
                used --;
                return ret;
            }
        }
        return NULL;
    }

    // Returns the number of (key,value) pairs in this map
    size_t size() 
    {
        return used;
    }
};