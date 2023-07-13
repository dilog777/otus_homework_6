#pragma once

#include "Model.hpp"



template<class Type, Type defaultValue>
class Matrix
{
public:
	using Model = Model<Type>;
	using ModelIndex = ModelIndex<Model, Type>;
	
	Matrix();

	int size() const;

	ModelIndex operator[](int index);

private:
	std::shared_ptr<Model> _model;
};



template<class Type, Type defaultValue>
Matrix<Type, defaultValue>::Matrix()
	: _model { new Model(defaultValue) }
{
}



template<class Type, Type defaultValue>
int Matrix<Type, defaultValue>::size() const
{
	return _model->size();
}



template<class Type, Type defaultValue>
typename ModelIndex<Model<Type>, Type> Matrix<Type, defaultValue>::operator[](int index)
{
	return _model->operator[](index);
}