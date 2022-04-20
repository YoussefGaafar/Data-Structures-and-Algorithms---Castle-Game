/** Header file for an array-based implementation of the ADT bag.
@file ArrayBag.h */
#pragma once

// ==== File Description =====
// The header file “ArrayBag.h” defines the class template that:
// inherits the BagInterface and implements its pure virtual functions using array.

#include "BagInterface.h"

// =========== The Class Declaration of the ArrayBag Class Template ===============

template<class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 100;
	ItemType items[DEFAULT_CAPACITY]; // Array of bag items
	int itemCount; // Current count of bag items
	int maxItems; // Max capacity of the bag
	// Returns either the index of the element in the array items that
	// contains the given target or -1, if the array does not contain
	// the target.
	int getIndexOf(const ItemType& target) const;

public:
	ArrayBag();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
	virtual const ItemType* toArray() const;

}; // end ArrayBag

// =========== Functions' Implementation of the ArrayBag Class Template ===============


// 0- int getIndexOf(const ItemType& target) const
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	bool found = false;
	int result = -1;
	int searchIndex = 0;
	// If the bag is empty, itemCount is zero, so loop is skipped
	while (!found && (searchIndex < itemCount))
	{
		if (items[searchIndex] == target)
		{
			found = true;
			result = searchIndex;
		}
		else
		{
			searchIndex++;
		} // end if
	} // end while
	return result;
} // end get IndexOf


// 1- ArrayBag();
template<class ItemType>
ArrayBag<ItemType>::ArrayBag() : itemCount(0), maxItems(DEFAULT_CAPACITY)
{
} // end default constructor


// 2- int getCurrentSize() const;
template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
} // end getCurrentSize


// 3- bool isEmpty() const;	
template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
} // end isEmpty


// 4- bool add(const ItemType& newEntry);
template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	} // end if
	return hasRoomToAdd;
} // end add


// 5- bool remove(const ItemType& anEntry);
template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
	int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	} // end if
	return canRemoveItem;
} // end remove


// 6- void clear();
template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
} // end clear


// 7- bool contains(const ItemType& anEntry) const;
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	// == Easy but not Efficient Implementation
	//return getFrequencyOf(target) > 0;

	// == Efficient Implementation
	bool found = false;
	int curIndex = 0; // Current array index
	while (!found && (curIndex < itemCount))
	{
		if (anEntry == items[curIndex])
		{
			found = true;
		} // end if
		curIndex++; // Increment to next entry
	} // end while
	return found;

} // end contains


// 8- int getFrequencyOf(const ItemType& anEntry) const;
template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0;
	int curIndex = 0; // Current array index
	while (curIndex < itemCount)
	{
		if (items[curIndex] == anEntry)
		{
			frequency++;
		} // end if
		curIndex++; // Increment to next entry
	} // end while
	return frequency;
} // end getFrequencyOf


// 9- virtual const ItemType* toArray() const;
template<class ItemType>
const ItemType* ArrayBag<ItemType>::toArray() const
{
	ItemType* outArr = new ItemType[itemCount];
	for (int i = 0; i < itemCount; i++)
		outArr[i] = items[i];
	return outArr;
} // end toVector