#pragma once

#include <array>
#include <map>



template<class Type, int dim>
class Model
{
public:
	using Key = std::array<int, dim>;
	using iterator = typename std::map<Key, Type>::iterator;
	static const int Dim = dim;

	Model(const Type &defaultValue);
	
	int size() const;

	Type value(const Key &key) const;
	void setValue(const Key &key, const Type &value);

	iterator begin();
	iterator end();

private:
	const Type _defaultValue;
	std::map<Key, Type> _values;
};



template<class Type, int dim>
Model<Type, dim>::Model(const Type &defaultValue)
	: _defaultValue { defaultValue }
{
}



template<class Type, int dim>
int Model<Type, dim>::size() const
{
	return _values.size();
}



template<class Type, int dim>
Type Model<Type, dim>::value(const Key &key) const
{
	if (_values.count(key))
		return _values.at(key);

	return _defaultValue;
}



template<class Type, int dim>
void Model<Type, dim>::setValue(const Key &key, const Type &value)
{
	if (value != _defaultValue)
		_values[key] = value;
	else
		_values.erase(key);
}



template<class Type, int dim>
typename Model<Type, dim>::iterator Model<Type, dim>::begin()
{
	return _values.begin();
}



template<class Type, int dim>
typename Model<Type, dim>::iterator Model<Type, dim>::end()
{
	return _values.end();
}
