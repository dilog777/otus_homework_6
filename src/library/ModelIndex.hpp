#pragma once

#include <list>

#include "Model.hpp"



template<class Model, class Type>
class ModelIndex
{
public:
	ModelIndex(Model *model);

	ModelIndex operator[](int index) const;
	ModelIndex &operator=(const Type &value);
	operator Type() const;

private:
	Model *_model { nullptr };
	typename Model::ModelKey _key;
};



template<class Model, class Type>
ModelIndex<Model, Type>::ModelIndex(Model *model)
	: _model { model }
{
}



template<class Model, class Type>
ModelIndex<Model, Type> ModelIndex<Model, Type>::operator[](int index) const
{
	ModelIndex subIndex(*this);
	subIndex._key.push_back(index);
	return subIndex;
}



template<class Model, class Type>
ModelIndex<Model, Type> &ModelIndex<Model, Type>::operator=(const Type &value)
{
	_model->setValue(_key, value);
	return *this;
}



template<class Model, class Type>
ModelIndex<Model, Type>::operator Type() const
{
	return _model->value(_key);
}
