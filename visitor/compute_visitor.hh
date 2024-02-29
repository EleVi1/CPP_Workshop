#pragma once
#include <cassert>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>

#include "add.hh"
#include "div.hh"
#include "leaf.hh"
#include "mul.hh"
#include "sub.hh"
#include "tree.hh"
#include "visitor.hh"

namespace visitor
{
    class ComputeVisitor : public Visitor
    {
    public:
        void visit(const tree::Tree& e) override;

        void visit(const tree::Node& e) override;

        void visit(const tree::AddNode& e) override;

        void visit(const tree::SubNode& e) override;

        void visit(const tree::MulNode& e) override;

        void visit(const tree::DivNode& e) override;

        void visit(const tree::Leaf& e) override;

        int get_value();

    private:
        int value_;
    };
} // namespace visitor