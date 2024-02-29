#include "compute_visitor.hh"

using namespace visitor;

void ComputeVisitor::visit(const tree::Tree& e)
{
    if (e.get_value() == "")
        return;
}

void ComputeVisitor::visit(const tree::Node& e)
{
    e.get_lhs()->accept(*this);
    e.get_rhs()->accept(*this);
}

void ComputeVisitor::visit(const tree::AddNode& e)
{
    e.get_lhs()->accept(*this);
    int g = value_;
    e.get_rhs()->accept(*this);
    int r = value_;
    value_ = g + r;
}

void ComputeVisitor::visit(const tree::SubNode& e)
{
    e.get_lhs()->accept(*this);
    int g = value_;
    e.get_rhs()->accept(*this);
    int r = value_;
    value_ = g - r;
}

void ComputeVisitor::visit(const tree::MulNode& e)
{
    e.get_lhs()->accept(*this);
    int g = value_;
    e.get_rhs()->accept(*this);
    int r = value_;
    value_ = g * r;
}

void ComputeVisitor::visit(const tree::DivNode& e)
{
    e.get_lhs()->accept(*this);
    int num = value_;
    e.get_rhs()->accept(*this);
    int denom = value_;
    if (denom == 0)
    {
        throw std::overflow_error("Division by zero exception");
    }
    value_ = num / denom;
}

void ComputeVisitor::visit(const tree::Leaf& e)
{
    std::stringstream leaf(e.get_value());
    leaf >> value_;
}

int ComputeVisitor::get_value()
{
    return value_;
}
