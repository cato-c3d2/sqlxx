/*!
 * @file make-expression.function.h++
 */

#ifndef SQLXX__EXPRESSION__MAKE_EXPRESSION_FUNCTION_HXX
#define SQLXX__EXPRESSION__MAKE_EXPRESSION_FUNCTION_HXX

#include <type_traits>

namespace sqlxx
{
inline namespace expression
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class forward declaration
    //
    ////////////////////////////////////////////////////////////////////////////

    class Expression;

    template<typename Type>
    class BasicLiteralExpression;

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function declaration
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief 式のオブジェクトを生成する
     *
     * @param[in] expression_or_literal_inner_value 式のオブジェクトまたはリテラルの内部値
     *
     * @return 式のオブジェクト
     *         @c expression_or_literal_inner_value が式のオブジェクトの場合は、
     *         @c expression_or_literal_inner_value を元に生成した式のオブジェクトを返却する。 @n
     *         @c expression_or_literal_inner_value がリテラルの内部値の場合は、
     *         @c expression_or_literal_inner_value を元に生成したリテラル式のオブジェクトを返却する。 @n
     */
    template<typename Type>
    auto make_expression(Type expression_or_literal_inner_value)
        -> Expression const *;

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function definition
    //
    ////////////////////////////////////////////////////////////////////////////

    inline namespace
    {
        template<typename Type, bool IS_BASE_OF_EXPRESSION = true>
        struct GetExpressionTypeImplementation
        {
            using ExpressionType = Type;
        };

        template<typename Type>
        struct GetExpressionTypeImplementation<Type, false>
        {
            using ExpressionType = BasicLiteralExpression<Type>;
        };

        template<typename Type>
        struct GetExpressionType :
            public GetExpressionTypeImplementation<
                Type,
                std::is_base_of<Expression, Type>::value>
        {};
    } // namespace

    template<typename Type>
    auto make_expression(Type expression_or_literal_inner_value)
        -> Expression const *
    {
        return new typename GetExpressionType<Type>::ExpressionType {
            expression_or_literal_inner_value
        };
    }
} // namespace expression
} // namespace sqlxx

#endif // SQLXX__EXPRESSION__MAKE_EXPRESSION_FUNCTION_HXX
