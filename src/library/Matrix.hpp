#pragma once

#include <memory>

#include "Model.hpp"
#include "ModelIndex.hpp"



template<class Type, Type defaultValue>
class Matrix
{
public:
	using Model = Model<Type, 2>;
	using ModelIndex = ModelIndex<Model, Type>;
	using iterator = typename Model::iterator;
	
	Matrix();

	int size() const;

	ModelIndex operator[](int index);

	iterator begin();
	iterator end();

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
typename Matrix<Type, defaultValue>::ModelIndex Matrix<Type, defaultValue>::operator[](int index)
{
	ModelIndex modelIndex { _model.get() };
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
