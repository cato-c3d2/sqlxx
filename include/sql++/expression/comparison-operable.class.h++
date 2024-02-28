/*!
 * @file comparison-operable.class.h++
 */

#ifndef SQLXX__EXPRESSION__COMPARISON_OPERABLE_CLASS_HXX
#define SQLXX__EXPRESSION__COMPARISON_OPERABLE_CLASS_HXX

#include <string>

#include <sql++/expression/condition-expression.class.h++>
#include <sql++/expression/expression.class.h++>
#include <sql++/expression/make-expression.function.h++>

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
     * @brief 式オブジェクトの比較演算子の機能を提供するクラス
     */
    class ComparisonOperable : public virtual Expression
    {
    public:
        /*!
         * @brief 等値比較演算式を生成する
         *
         * このオブジェクトを左辺の式、
         * @c operand を右辺の式とした、等値比較演算式を生成する。 @n
         *
         * このメンバ関数の名称は、標準ライブラリ関数
         * @c std::equal_to （ @c \<functional\> ）を参考に命名した。 @n
         *
         * @param[in] operand 右辺の式のオブジェクトまたはリテラルの内部値
         *
         * @return 等値比較演算式
         */
        template<typename Type>
        auto equal_to(Type operand) const -> ConditionExpression const;

        /*!
         * @brief 非等値比較演算式を生成する
         *
         * このオブジェクトを左辺の式、
         * @c operand を右辺の式とした、非等値比較演算式を生成する。 @n
         *
         * このメンバ関数の名称は、標準ライブラリ関数
         * @c std::not_equal_to （ @c \<functional\> ）を参考に命名した。 @n
         *
         * @param[in] operand 右辺の式のオブジェクトまたはリテラルの内部値
         *
         * @return 非等値比較演算式
         */
        template<typename Type>
        auto not_equal_to(Type operand) const -> ConditionExpression const;

        /*!
         * @brief 比較演算式（小なり）を生成する
         *
         * このオブジェクトを左辺の式、
         * @c operand を右辺の式とした、比較演算式（小なり）を生成する。
         *
         * このメンバ関数の名称は、標準ライブラリ関数
         * @c std::less_equal （ @c \<functional\> ）を参考に命名した。
         *
         * @param[in] operand 右辺の式のオブジェクトまたはリテラルの内部値
         *
         * @return 比較演算式（小なり）
         */
        template<typename Type>
        auto less(Type operand) const -> ConditionExpression const;

        /*!
         * @brief 比較演算式（以下）を生成する
         *
         * このオブジェクトを左辺の式、
         * @c operand を右辺の式とした、比較演算式（以下）を生成する。
         *
         * このメンバ関数の名称は、標準ライブラリ関数
         * @c std::less_equal （ @c \<functional\> ）を参考に命名した。
         *
         * @param[in] operand 右辺の式のオブジェクトまたはリテラルの内部値
         *
         * @return 比較演算式（以下）
         */
        template<typename Type>
        auto less_equal(Type operand) const -> ConditionExpression const;

        /*!
         * @brief 比較演算式（大なり）を生成する
         *
         * このオブジェクトを左辺の式、
         * @c operand を右辺の式とした、比較演算式（大なり）を生成する。
         *
         * このメンバ関数の名称は、標準ライブラリ関数
         * @c std::less_equal （ @c \<functional\> ）を参考に命名した。
         *
         * @param[in] operand 右辺の式のオブジェクトまたはリテラルの内部値
         *
         * @return 比較演算式（大なり）
         */
        template<typename Type>
        auto greater(Type operand) const -> ConditionExpression const;

        /*!
         * @brief 比較演算式（以上）を生成する
         *
         * このオブジェクトを左辺の式、
         * @c operand を右辺の式とした、比較演算式（以上）を生成する。
         *
         * このメンバ関数の名称は、標準ライブラリ関数
         * @c std::less_equal （ @c \<functional\> ）を参考に命名した。
         *
         * @param[in] operand 右辺の式のオブジェクトまたはリテラルの内部値
         *
         * @return 比較演算式（以上）
         */
        template<typename Type>
        auto greater_equal(Type operand) const -> ConditionExpression const;

        /*!
         * @brief IS 演算式を生成する
         *
         * このオブジェクトを左辺の式、
         * @c operand を右辺の式とした、 IS 演算式を生成する。
         *
         * @param[in] operand 右辺の式のオブジェクトまたはリテラルの内部値
         *
         * @return IS 演算式
         */
        template<typename Type>
        auto is(Type operand) const -> ConditionExpression const;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    template<typename Type>
    auto ComparisonOperable::equal_to(Type operand) const
        -> ConditionExpression const
    {
        return ConditionExpression { "=",
                                     this->clone(),
                                     make_expression(operand) };
    }

    template<typename Type>
    auto ComparisonOperable::not_equal_to(Type operand) const
        -> ConditionExpression const
    {
        return ConditionExpression { "<>",
                                     this->clone(),
                                     make_expression(operand) };
    }

    template<typename Type>
    auto ComparisonOperable::less(Type operand) const
        -> ConditionExpression const
    {
        return ConditionExpression { "<",
                                     this->clone(),
                                     make_expression(operand) };
    }

    template<typename Type>
    auto ComparisonOperable::less_equal(Type operand) const
        -> ConditionExpression const
    {
        return ConditionExpression {
            "<=", this->clone(), make_expression(operand)
        };
    }

    template<typename Type>
    auto ComparisonOperable::greater(Type operand) const
        -> ConditionExpression const
    {
        return ConditionExpression { ">",
                                     this->clone(),
                                     make_expression(operand) };
    }

    template<typename Type>
    auto ComparisonOperable::greater_equal(Type operand) const
        -> ConditionExpression const
    {
        return ConditionExpression {
            ">=", this->clone(), make_expression(operand)
        };
    }

    template<typename Type>
    auto ComparisonOperable::is(Type operand) const -> ConditionExpression const
    {
        return ConditionExpression { "IS",
                                     this->clone(),
                                     make_expression(operand) };
    }
} // namespace expression
} // namespace sqlxx

#endif // SQLXX__EXPRESSION__COMPARISON_OPERABLE_CLASS_HXX
