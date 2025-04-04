/*!
 * @file comparison-operable.class.h++
 */

#ifndef SQLXX__EXPRESSION__OPERATION__COMPARISON_OPERABLE_CLASS_HXX
#define SQLXX__EXPRESSION__OPERATION__COMPARISON_OPERABLE_CLASS_HXX

#include <string>

#include <sql++/expression/expression.class.h++>
#include <sql++/expression/make-expression.function.h++>
#include <sql++/expression/operation/binary-operation-kind.enum-class.h++>
#include <sql++/expression/operation/binary-operation.class.h++>

namespace sqlxx
{
inline namespace expression
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief ≪比較演算可能≫を表現する Mix-in クラス
     *
     * このクラスは派生クラスに「各種≪比較演算式≫を生成する機能」を混入する Mix-in クラスである。 @n
     */
    class ComparisonOperable : public virtual Expression
    {
    public:
        /*!
         * @brief ≪等値比較演算式≫を生成する
         *
         * このオブジェクトを左辺の≪式≫、
         * @c operand を右辺の≪式≫とした、≪等値比較演算式≫を生成する。 @n
         * @n
         * このメンバ関数の名称は、標準ライブラリ関数
         * @c std::equal_to （ @c \<functional\> ）を参考に命名した。 @n
         *
         * @param[in] operand 右辺の≪式≫ @n
         *                    演算される≪式≫として≪式≫のオブジェクトだけではなく、≪リテラル式≫の内部値を指定することが可能。 @n
         *
         * @return ≪等値比較演算式≫
         */
        template<typename Type>
        auto equal_to(Type operand) const -> BinaryOperation;

        /*!
         * @brief ≪非等値比較演算式≫を生成する
         *
         * このオブジェクトを左辺の≪式≫、
         * @c operand を右辺の≪式≫とした、≪非等値比較演算式≫を生成する。 @n
         * @n
         * このメンバ関数の名称は、標準ライブラリ関数
         * @c std::not_equal_to （ @c \<functional\> ）を参考に命名した。 @n
         *
         * @param[in] operand 右辺の≪式≫ @n
         *                    演算される≪式≫として≪式≫のオブジェクトだけではなく、≪リテラル式≫の内部値を指定することが可能。 @n
         *
         * @return ≪非等値比較演算式≫
         */
        template<typename Type>
        auto not_equal_to(Type operand) const -> BinaryOperation;

        /*!
         * @brief ≪比較演算式（小なり）≫を生成する
         *
         * このオブジェクトを左辺の≪式≫、
         * @c operand を右辺の≪式≫とした、≪比較演算式（小なり）≫を生成する。 @n
         * @n
         * このメンバ関数の名称は、標準ライブラリ関数
         * @c std::less_equal （ @c \<functional\> ）を参考に命名した。 @n
         *
         * @param[in] operand 右辺の≪式≫ @n
         *                    演算される≪式≫として≪式≫のオブジェクトだけではなく、≪リテラル式≫の内部値を指定することが可能。 @n
         *
         * @return ≪比較演算式（小なり）≫
         */
        template<typename Type>
        auto less(Type operand) const -> BinaryOperation;

        /*!
         * @brief ≪比較演算式（以下）≫を生成する
         *
         * このオブジェクトを左辺の≪式≫、
         * @c operand を右辺の≪式≫とした、≪比較演算式（以下）≫を生成する。 @n
         * @n
         * このメンバ関数の名称は、標準ライブラリ関数
         * @c std::less_equal （ @c \<functional\> ）を参考に命名した。 @n
         *
         * @param[in] operand 右辺の≪式≫ @n
         *                    演算される≪式≫として≪式≫のオブジェクトだけではなく、≪リテラル式≫の内部値を指定することが可能。 @n
         *
         * @return ≪比較演算式（以下）≫
         */
        template<typename Type>
        auto less_equal(Type operand) const -> BinaryOperation;

        /*!
         * @brief ≪比較演算式（大なり）≫を生成する
         *
         * このオブジェクトを左辺の≪式≫、
         * @c operand を右辺の≪式≫とした、≪比較演算式（大なり）≫を生成する。 @n
         * @n
         * このメンバ関数の名称は、標準ライブラリ関数
         * @c std::less_equal （ @c \<functional\> ）を参考に命名した。 @n
         *
         * @param[in] operand 右辺の≪式≫ @n
         *                    演算される≪式≫として≪式≫のオブジェクトだけではなく、≪リテラル式≫の内部値を指定することが可能。 @n
         *
         * @return ≪比較演算式（大なり）≫
         */
        template<typename Type>
        auto greater(Type operand) const -> BinaryOperation;

        /*!
         * @brief ≪比較演算式（以上）≫を生成する
         *
         * このオブジェクトを左辺の≪式≫、
         * @c operand を右辺の≪式≫とした、≪比較演算式（以上）≫を生成する。 @n
         * @n
         * このメンバ関数の名称は、標準ライブラリ関数
         * @c std::less_equal （ @c \<functional\> ）を参考に命名した。 @n
         *
         * @param[in] operand 右辺の≪式≫ @n
         *                    演算される≪式≫として≪式≫のオブジェクトだけではなく、≪リテラル式≫の内部値を指定することが可能。 @n
         *
         * @return ≪比較演算式（以上）≫
         */
        template<typename Type>
        auto greater_equal(Type operand) const -> BinaryOperation;

        /*!
         * @brief ≪IS演算式≫を生成する
         *
         * このオブジェクトを左辺の≪式≫、
         * @c operand を右辺の≪式≫とした、≪IS演算式≫を生成する。 @n
         *
         * @param[in] operand 右辺の≪式≫ @n
         *                    演算される≪式≫として≪式≫のオブジェクトだけではなく、≪リテラル式≫の内部値を指定することが可能。 @n
         *
         * @return ≪IS演算式≫
         */
        template<typename Type>
        auto is(Type operand) const -> BinaryOperation;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    template<typename Type>
    auto ComparisonOperable::equal_to(Type operand) const -> BinaryOperation
    {
        return BinaryOperation { BinaryOperationKind::EqualTo,
                                 *this,
                                 *make_expression(operand) };
    }

    template<typename Type>
    auto ComparisonOperable::not_equal_to(Type operand) const -> BinaryOperation
    {
        return BinaryOperation { BinaryOperationKind::NotEqualTo,
                                 *this,
                                 *make_expression(operand) };
    }

    template<typename Type>
    auto ComparisonOperable::less(Type operand) const -> BinaryOperation
    {
        return BinaryOperation { BinaryOperationKind::Less,
                                 *this,
                                 *make_expression(operand) };
    }

    template<typename Type>
    auto ComparisonOperable::less_equal(Type operand) const -> BinaryOperation
    {
        return BinaryOperation { BinaryOperationKind::LessEqual,
                                 *this,
                                 *make_expression(operand) };
    }

    template<typename Type>
    auto ComparisonOperable::greater(Type operand) const -> BinaryOperation
    {
        return BinaryOperation { BinaryOperationKind::Greater,
                                 *this,
                                 *make_expression(operand) };
    }

    template<typename Type>
    auto ComparisonOperable::greater_equal(Type operand) const
        -> BinaryOperation
    {
        return BinaryOperation { BinaryOperationKind::GreaterEqual,
                                 *this,
                                 *make_expression(operand) };
    }

    template<typename Type>
    auto ComparisonOperable::is(Type operand) const -> BinaryOperation
    {
        return BinaryOperation { BinaryOperationKind::Is,
                                 *this,
                                 *make_expression(operand) };
    }
} // namespace expression
} // namespace sqlxx

#endif // SQLXX__EXPRESSION__OPERATION__COMPARISON_OPERABLE_CLASS_HXX
