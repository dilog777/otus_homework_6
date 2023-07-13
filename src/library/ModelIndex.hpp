#pragma once

#include <list>
#include <memory>

#include "Model.hpp"

using ModelKey = std::list<int>;



template<class Model, class Type>
class ModelIndex
{
public:
	ModelIndex(const std::shared_ptr<Model> &model);
	virtual ~ModelIndex() = default;

	ModelIndex operator[](int index) const;
	ModelIndex &operator=(const Type &value);
	operator Type() const;

	const ModelKey &key() const;
	Type value(const ModelIndex &index) const;

private:
	std::weak_ptr<Model> _model;
	ModelKey _key;
};



template<class Model, class Type>
ModelIndex<Model, Type>::ModelIndex(const std::shared_ptr<Model> &model)
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
	if (auto model = _model.lock())
		model->setValue(*this, value);

	return *this;
}



template<class Model, class Type>
ModelIndex<Model, Type>::operator Type() const
{
	if (auto model = _model.lock())
		return model->value(*this);

	return {};
}



template<class Model, class Type>
const ModelKey &ModelIndex<Model, Type>::key() const
{
	return _key;
}



template<class Model, class Type>
Type ModelIndex<Model, Type>::value(const ModelIndex &index) const
{
	if (auto model = _model.lock())
		return model->value(*this);

	return {};
}
