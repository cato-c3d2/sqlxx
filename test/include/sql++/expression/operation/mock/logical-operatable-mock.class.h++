/*!
 * @file logical-operatable-mock.class.h++
 */

// FIXME 【要修正】ファイル名を変更する予定 : logical-operatable*.h++ => logical-operable*.h++

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__MOCK__LOGICAL_OPERATABLE_MOCK_CLASS_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__MOCK__LOGICAL_OPERATABLE_MOCK_CLASS_HXX

#include <iostream>
#include <string>

#include <sql++/expression/expression.class.h++>
#include <sql++/expression/operation/binary-operation-kind.enum-class.h++>
#include <sql++/expression/operation/logical-operatable.class.h++>

namespace sqlxx::test
{
inline namespace expression
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief @c LogicalOperable クラスを継承したモッククラス
     */
    class LogicalOperableMock :
        public virtual LogicalOperable<LogicalOperableMock>
    {
    public:
        /*!
         * @brief デフォルトコンストラクタ
         */
        LogicalOperableMock() : _operation_kind(BinaryOperationKind::None)
        {}

        /*!
         * @brief コンストラクタ
         *
         * @param[in] operation_kind ≪二項演算種別≫
         * @param[in] left_operand   左辺の≪式≫（使用しない）
         * @param[in] right_operand  右辺の≪式≫（使用しない）
         */
        LogicalOperableMock(
            BinaryOperationKind operation_kind,
            Expression const &  left_operand,
            Expression const &  right_operand)
            : _operation_kind(operation_kind)
        {}

        /*!
         * @brief 仮想デストラクタ
         */
        virtual ~LogicalOperableMock() override = default;

        /*!
         * @brief コピーコンストラクタ
         *
         * @param[in] origin コピー元のオブジェクト
         */
        LogicalOperableMock(LogicalOperableMock const & origin)
        {
            this->_operation_kind = origin._operation_kind;
        };

        /*!
         * @brief この式の文字列表現を返却する
         *
         * @return この式の文字列表現
         */
        virtual auto evaluate() const -> std::string override;

        /*!
         * @brief このオブジェクトを複製する
         *
         * @return 複製したオブジェクトのポインタ
         */
        virtual auto clone() const -> LogicalOperableMock * override;

    private:
        /*!
         * @brief ≪二項演算種別≫
         */
        BinaryOperationKind _operation_kind;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function declaration
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief ストリーム出力演算
     *
     * @param[in] out     出力ストリーム
     * @param[in] operand モッククラスその一のオブジェクト
     *
     * @return 出力ストリーム
     */
    auto operator<<(std::ostream & out, LogicalOperableMock const & operand)
        -> std::ostream &;

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    auto LogicalOperableMock::evaluate() const -> std::string
    {
        using namespace std::literals::string_literals;

        std::string operation_kind;
        if (this->_operation_kind != BinaryOperationKind::None) {
            operation_kind =
                sqlxx::expression::to_string(this->_operation_kind);
        } else {
            operation_kind = "(operation_kind-none)";
        }

        return "L "s + operation_kind + " R"s;
    }

    auto LogicalOperableMock::clone() const -> LogicalOperableMock *
    {
        return new LogicalOperableMock { *this };
    }

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function definition
    //
    ////////////////////////////////////////////////////////////////////////////

    auto operator<<(std::ostream & out, LogicalOperableMock const & operand)
        -> std::ostream &
    {
        return out << operand.evaluate();
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__MOCK__LOGICAL_OPERATABLE_MOCK_CLASS_HXX */
