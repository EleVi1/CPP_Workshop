#pragma once

template <typename U, typename V = U>
concept impl_basic_op = requires(U u, V v)
{
    { u + v };
    { v + u };
    { +u };
    { +v };
    { -u };
    { -v };
    { u - v };
    { v - u };
    { u * v };
    { v * u };
    { v / u };
    { u / v };
};

template <typename U, typename V = U>
concept impl_modulo = requires(U u, V v)
{
    { v % u };
    { u % v };
};

template <typename U, typename V = U>
concept impl_bitwise_op = requires(U u, V v)
{
    { ~u };
    { ~v };
    { v | u };
    { u | v };
    { v ^ u };
    { u ^ v };
    { v << u };
    { u << v };
    { v >> u };
    { u >> v };
    { v & u };
    { u & v };
};

template <typename U, typename V = U>
concept impl_arith_op =
    impl_basic_op<U, V> && impl_bitwise_op<U, V> && impl_modulo<U, V>;