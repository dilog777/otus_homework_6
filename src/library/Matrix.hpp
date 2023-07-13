#pragma once

#include "Model.hpp"



template<class Type, Type defaultValue>
class Matrix
{
public:
	Matrix();

	int size() const;

	ModelIndex<Model<Type>, Type> operator[](int index);

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
	return _model->operator[](index);
}