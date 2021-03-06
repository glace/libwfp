#include "stdafx.h"
#include "conditionprotocol.h"
#include "libwfp/internal/conditionassembler.h"
#include <winsock2.h>

using ConditionAssembler = ::wfp::internal::ConditionAssembler;

namespace wfp::conditions {

ConditionProtocol::ConditionProtocol(Protocol protocol)
	: m_protocol(protocol)
{
	m_assembled = ConditionAssembler::Uint8
	(
		identifier(),
		FWP_MATCH_EQUAL,
		Protocol::Tcp == m_protocol ? UINT8(IPPROTO_TCP) : UINT8(IPPROTO_UDP)
	);
}

std::wstring ConditionProtocol::toString() const
{
	return
	(
		Protocol::Tcp == m_protocol
		? L"protocol = TCP"
		: L"protocol = UDP"
	);
}

const GUID &ConditionProtocol::identifier() const
{
	return FWPM_CONDITION_IP_PROTOCOL;
}

const FWPM_FILTER_CONDITION0 &ConditionProtocol::condition() const
{
	return *reinterpret_cast<FWPM_FILTER_CONDITION0 *>(m_assembled.data());
}

//static
std::unique_ptr<ConditionProtocol> ConditionProtocol::Tcp()
{
	return std::unique_ptr<ConditionProtocol>(new ConditionProtocol(Protocol::Tcp));
}

//static
std::unique_ptr<ConditionProtocol> ConditionProtocol::Udp()
{
	return std::unique_ptr<ConditionProtocol>(new ConditionProtocol(Protocol::Udp));
}

}
