/*
 * Copyright (C) 2011 Matias Valdenegro <matias.valdenegro@gmail.com>
 * This file is part of Epic Framework.
 *
 * Epic Framework is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * Epic Framework is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Epic Framework.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef EPIC_CORE_HASHTABLE_H_
#define EPIC_CORE_HASHTABLE_H_

#include <epic.core/LinkedList.h>

//template<typename T>
//size_t hash(const T& e);

inline size_t hash(char e) { return static_cast<size_t>(e); }
inline size_t hash(signed char e) { return static_cast<size_t>(e); }
inline size_t hash(unsigned char e) { return static_cast<size_t>(e); }

inline size_t hash(short e) { return static_cast<size_t>(e); }
inline size_t hash(unsigned short e) { return static_cast<size_t>(e); }

inline size_t hash(int e) { return static_cast<size_t>(e); }
inline size_t hash(unsigned int e) { return static_cast<size_t>(e); }

inline size_t hash(long e) { return static_cast<size_t>(e); }
inline size_t hash(unsigned long e) { return static_cast<size_t>(e); }

inline size_t hash(long long e) { return static_cast<size_t>(e); }
inline size_t hash(unsigned long long e) { return static_cast<size_t>(e); }

size_t hash(const char *str)
{
    size_t h = 0;
    int c;

    while((c = *str++) != '\0') {
        h = c + (h << 6) + (h << 16) - h;
    }

    return h;
}

namespace Epic {
    namespace Core {

        template<typename Key, typename Value>
        class HashTable
        {
            public:
                HashTable(size_t capacity = 17) : mCapacity(capacity), mBuckets(new LinkedList<HashNode>[capacity])
                {
                }

                ~HashTable()
                {
                    delete [] mBuckets;
                }

                void insert(const Key& key, const Value& value)
                {
                    getBucket(key).append(HashNode(key, value));
                }

                bool remove(const Key& key)
                {
                    bool removed = false;
                    LinkedList<HashNode>& bucket = getBucket(key);

                    for(typename LinkedList<HashNode>::Iterator it = bucket.begin(); it != bucket.end();) {

                        if(it->key == key) {

                            it = bucket.remove(it);
                            removed = true;

                        } else {

                            it++;
                        }
                    }

                    return removed;
                }

                bool contains(const Key& key) const
                {
                    const LinkedList<HashNode>& bucket = getBucket(key);

                    for(typename LinkedList<HashNode>::ConstIterator it = bucket.constBegin(); it != bucket.constEnd(); it++) {

                        if(it->key == key) {
                            return true;
                        }
                    }

                    return false;
                }

                Value lookup(const Key& key) const
                {
                    const LinkedList<HashNode>& bucket = getBucket(key);

                    for(typename LinkedList<HashNode>::ConstIterator it = bucket.constBegin(); it != bucket.constEnd(); it++) {

                        if(it->key == key) {
                            return it->value;
                        }
                    }

                    return Value();
                }

                Value& operator[](const Key& key)
                {
                    if(!contains(key)) {
                        insert(key, Value());
                    }

                    LinkedList<HashNode>& bucket = getBucket(key);

                    for(typename LinkedList<HashNode>::Iterator it = bucket.begin(); it != bucket.end(); it++) {

                        if(it->key == key) {
                            return it->value;
                        }
                    }

                    EPIC_ASSERT(false);
                }

                const Value& operator[](const Key& key) const
                {
                    return lookup(key);
                }

                bool isEmpty() const
                {
                    for(size_t i = 0; i < mCapacity; i++) {

                        if(!mBuckets[i].isEmpty()) {
                            return false;
                        }
                    }

                    return true;
                }

                size_t count() const
                {
                    size_t ret = 0;

                    for(size_t i = 0; i < mCapacity; i++) {
                        ret += mBuckets[i].count();
                    }

                    return ret;
                }

            private:
                class HashNode
                {
                    public:
                        HashNode(Key k, Value v) : key(k), value(v)
                        {
                        }

                        Key     key;
                        Value   value;
                };

                LinkedList<HashNode>& getBucket(const Key& key)
                {
                    return mBuckets[hash(key) % mCapacity];
                }

                const LinkedList<HashNode>& getBucket(const Key& key) const
                {
                    return mBuckets[hash(key) % mCapacity];
                }


                size_t mCapacity;
                LinkedList<HashNode> *mBuckets;
        };

    }
}


#endif /* EPIC_CORE_HASHTABLE_H_ */
