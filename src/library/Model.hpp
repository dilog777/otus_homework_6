#pragma once

#include <list>
#include <map>



template<class Type>
class Model
{
public:
	Model(const Type &defaultValue);
	
	int size() const;

	using ModelKey = std::list<int>;
	Type value(const ModelKey &key) const;
	void setValue(const ModelKey &key, const Type &value);

	using iterator = typename std::map<ModelKey, Type>::iterator;
	iterator begin();
	iterator end();

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
Type Model<Type>::value(const ModelKey &key) const
{
	if (_values.count(key))
		return _values.at(key);

	return _defaultValue;
}



template<class Type>
void Model<Type>::setValue(const ModelKey &key, const Type &value)
{
	if (value != _defaultValue)
		_values[key] = value;
	else
		_values.erase(key);
}



template<class Type>
typename Model<Type>::iterator Model<Type>::begin()
{
	return _values.begin();
}



template<class Type>
typename Model<Type>::iterator Model<Type>::end()
{
	return _values.end();
}
