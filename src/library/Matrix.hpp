#pragma once

#include <memory>

#include "Model.hpp"
#include "ModelIndex.hpp"



template<class Type, Type defaultValue>
class Matrix
{
public:
	using ModelT = Model<Type, 2>;
	using ModelIndexT = ModelIndex<ModelT, Type>;
	using iterator = typename ModelT::iterator;
	
	Matrix();

	int size() const;

	ModelIndexT operator[](int index);

	iterator begin();
	iterator end();

private:
	std::shared_ptr<ModelT> _model;
};



template<class Type, Type defaultValue>
Matrix<Type, defaultValue>::Matrix()
	: _model { new ModelT(defaultValue) }
{
}



template<class Type, Type defaultValue>
int Matrix<Type, defaultValue>::size() const
{
	return _model->size();
}



template<class Type, Type defaultValue>
typename Matrix<Type, defaultValue>::ModelIndexT Matrix<Type, defaultValue>::operator[](int index)
{
	ModelIndexT modelIndex { _model.get() };
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
