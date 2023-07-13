#pragma once

#include <memory>

#include "Model.hpp"
#include "ModelIndex.hpp"



template<class Type, Type defaultValue>
class Matrix
{
public:
	Matrix();

	int size() const;

	ModelIndex<Model<Type>, Type> operator[](int index);

	using iterator = typename Model<Type>::iterator;
	iterator begin();
	iterator end();

private:
	std::shared_ptr<Model<Type>> _model;
};



template<class Type, Type defaultValue>
Matrix<Type, defaultValue>::Matrix()
	: _model { new Model<Type>(defaultValue) }
{
}



template<class Type, Type defaultValue>
int Matrix<Type, defaultValue>::size() const
{
	return _model->size();
}



template<class Type, Type defaultValue>
ModelIndex<Model<Type>, Type> Matrix<Type, defaultValue>::operator[](int index)
{
	auto modelIndex = ModelIndex<Model<Type>, Type>(_model.get());
	return modelIndex[index];
}



template<class Type, Type defaultValue>
typename Matrix<Type, defaultValue>::iterator Matrix<Type, defaultValue>::begin()
{
	return _model->begin();
}



template<class Type, Type defaultValue>
typename Matrix<Type, defaultValue>::iterator Matrix<Type, defaultValue>::end()
{
	return _model->end();
}
