#pragma once

#include <cassert>

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
	typename Model::Key _key {};
	int _dimIndex { 0 };
};



template<class Model, class Type>
ModelIndex<Model, Type>::ModelIndex(Model *model)
	: _model { model }
{
}



template<class Model, class Type>
ModelIndex<Model, Type> ModelIndex<Model, Type>::operator[](int index) const
{
	assert(_dimIndex < Model::Dim);
	
	ModelIndex subIndex(*this);
	subIndex._key[subIndex._dimIndex++] = index;
	return subIndex;
}



template<class Model, class Type>
ModelIndex<Model, Type> &ModelIndex<Model, Type>::operator=(const Type &value)
{
	assert(_dimIndex == Model::Dim);

	_model->setValue(_key, value);
	return *this;
}



template<class Model, class Type>
ModelIndex<Model, Type>::operator Type() const
{
	assert(_dimIndex == Model::Dim);

	return _model->value(_key);
}
