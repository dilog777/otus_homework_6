#pragma once

#include <list>
#include <map>
#include <memory>

#include "ModelIndex.hpp"

using ModelKey = std::list<int>;



template<class Type>
class Model : public std::enable_shared_from_this<Model<Type>>
{
public:
	using ModelIndex = ModelIndex<Model, Type>;
	
	Model(const Type &defaultValue);
	
	int size() const;

	ModelIndex operator[](int index);

	Type value(const ModelIndex &index) const;
	void setValue(const ModelIndex &index, const Type &value);

private:
	const Type _defaultValue;
	std::map<ModelKey, Type> _values;
};



template<class Type>
Model<Type>::Model(const Type &defaultValue)
	: _defaultValue { defaultValue }
{
}



template<class Type>
int Model<Type>::size() const
{
	return _values.size();
}



template<class Type>
typename Model<Type>::ModelIndex Model<Type>::operator[](int index)
{
	auto modelIndex = ModelIndex(shared_from_this());
	return modelIndex[index];
}



template<class Type>
Type Model<Type>::value(const ModelIndex &index) const
{
	auto &key = index.key();
	if (_values.count(key))
		return _values.at(key);

	return _defaultValue;
}



template<class Type>
void Model<Type>::setValue(const ModelIndex &index, const Type &value)
{
	auto &key = index.key();
	if (value != _defaultValue)
		_values[key] = value;
	else
		_values.erase(key);
}
