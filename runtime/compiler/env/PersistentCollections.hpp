#ifndef PERSISTENT_COLLECTIONS_H
#define PERSISTENT_COLLECTIONS_H

#include <vector>
#include <unordered_map>
#include <unordered_set>

template<typename T>
using PersistentVectorAllocator = TR::typed_allocator<T, TR::PersistentAllocator&>;
template<typename T>
using PersistentVector = std::vector<T, PersistentVectorAllocator<T>>;

template<typename T>
using PersistentUnorderedSetAllocator = TR::typed_allocator<T, TR::PersistentAllocator&>;
template<typename T>
using PersistentUnorderedSet = std::unordered_set<T, std::hash<T>, std::equal_to<T>, PersistentUnorderedSetAllocator<T>>;

template<typename T, typename U>
using PersistentUnorderedMapAllocator = TR::typed_allocator<std::pair<const T, U>, TR::PersistentAllocator&>;
template<typename T, typename U>
using PersistentUnorderedMap = std::unordered_map<T, U, std::hash<T>, std::equal_to<T>, PersistentUnorderedMapAllocator<T, U>>;

template<typename T, typename U>
using UnorderedMapAllocator = TR::typed_allocator<std::pair<const T, U>, TR::Region&>;
template<typename T, typename U>
using UnorderedMap = std::unordered_map<T, U, std::hash<T>, std::equal_to<T>, UnorderedMapAllocator<T, U>>;

template<typename T>
using VectorAllocator = TR::typed_allocator<T, TR::Region&>;
template<typename T>
using Vector = std::vector<T, VectorAllocator<T>>;

#endif
