/*!
 * @file logical-operatable.class.h++
 */

// FIXME 【要修正】ファイル名を変更する予定 : logical-operatable*.h++ => logical-operable*.h++

#ifndef SQLXX__EXPRESSION__OPERATION__LOGICAL_OPERATABLE_CLASS_HXX
#define SQLXX__EXPRESSION__OPERATION__LOGICAL_OPERATABLE_CLASS_HXX

#include <string>

#include <sql++/expression/expression.class.h++>
#include <sql++/expression/operation/binary-operation-kind.enum-class.h++>

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
     * @brief ≪論理演算可能≫を表現する Mix-in クラス
     *
     * このクラスは派生クラスに「各種≪二項論理演算式≫を生成する機能」を混入する Mix-in クラスである。 @n
     * @n
     * NOTE 相互参照によるコンパイルエラーを避けるために、
     *      @c BinaryOperation を型パラメータとして受け取るように実装している。 @n
     */
    template<typename BinaryOperationType>
    class LogicalOperable : public virtual Expression
    {
    public:
        /*!
         * @brief ≪論理積演算式≫を生成する
         *
         * このオブジェクトを左辺の≪式≫、
         * @c operand を右辺の≪式≫とした、≪論理積演算式≫を生成する。 @n
         * @n
         * このメンバ関数の名称は、標準ライブラリ関数
         * @c std::logical_and （ @c \<functional\> ）を参考に命名した。 @n
         *
         * @param[in] operand 右辺の≪式≫
         *
         * @return ≪論理積演算式≫
         */
        auto logical_and(Expression const & operand) const
            -> BinaryOperationType;

        /*!
         * @brief ≪論理和演算式≫を生成する
         *
         * このオブジェクトを左辺の≪式≫、
         * @c operand を右辺の≪式≫とした、≪論理和演算式≫を生成する。 @n
         * @n
         * このメンバ関数の名称は、標準ライブラリ関数
         * @c std::logical_or （ @c \<functional\> ）を参考に命名した。 @n
         *
         * @param[in] operand 右辺の≪式≫
         *
         * @return ≪論理和演算式≫
         */
        auto logical_or(Expression const & operand) const
            -> BinaryOperationType;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    template<typename BinaryOperationType>
    auto LogicalOperable<BinaryOperationType>::logical_and(
        Expression const & operand) const -> BinaryOperationType
    {
        return BinaryOperationType { BinaryOperationKind::LogicalAnd,
                                     *this,
                                     operand };
    }

    template<typename BinaryOperationType>
    auto LogicalOperable<BinaryOperationType>::logical_or(
        Expression const & operand) const -> BinaryOperationType
    {
        return BinaryOperationType { BinaryOperationKind::LogicalOr,
                                     *this,
                                     operand };
    }
} // namespace expression
} // namespace sqlxx

#endif // SQLXX__EXPRESSION__OPERATION__LOGICAL_OPERATABLE_CLASS_HXX
