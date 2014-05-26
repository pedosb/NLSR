#include <iostream>
#include <string>
#include <cmath>
#include <limits>


#include "adjacent.hpp"
#include "logger.hpp"

namespace nlsr {

INIT_LOGGER("Adjacent");

using namespace std;

const float Adjacent::DEFAULT_LINK_COST = 10.0;

Adjacent::Adjacent()
    : m_name()
    , m_connectingFaceUri()
    , m_linkCost(DEFAULT_LINK_COST)
    , m_status(ADJACENT_STATUS_INACTIVE)
    , m_interestTimedOutNo(0)
{
}

Adjacent::Adjacent(const ndn::Name& an)
    : m_name(an)
    , m_connectingFaceUri()
    , m_linkCost(DEFAULT_LINK_COST)
    , m_status(ADJACENT_STATUS_INACTIVE)
    , m_interestTimedOutNo(0)
  {
  }

Adjacent::Adjacent(const ndn::Name& an, const std::string& cfu,  double lc,
          uint32_t s, uint32_t iton)
{
  m_name = an;
  m_connectingFaceUri = cfu;
  m_linkCost = lc;
  m_status = s;
  m_interestTimedOutNo = iton;
}

bool
Adjacent::operator==(const Adjacent& adjacent) const
{
  return (m_name == adjacent.getName()) &&
         (m_connectingFaceUri == adjacent.getConnectingFaceUri()) &&
         (std::abs(m_linkCost - adjacent.getLinkCost()) <
          std::numeric_limits<double>::epsilon()) ;
}

bool
Adjacent::compare(const ndn::Name& adjacencyName)
{
  return m_name == adjacencyName;
}

void
Adjacent::writeLog()
{
  _LOG_DEBUG("Adjacent : " << m_name);
  _LOG_DEBUG("Connecting FaceUri: " << m_connectingFaceUri);
  _LOG_DEBUG("Link Cost: " << m_linkCost);
  _LOG_DEBUG("Status: " << m_status);
  _LOG_DEBUG("Interest Timed out: " << m_interestTimedOutNo);
}

std::ostream&
operator<<(std::ostream& os, const Adjacent& adj)
{
  os << "Adjacent : " << adj.getName() << endl;
  os << "Connecting FaceUri: " << adj.getConnectingFaceUri() << endl;
  os << "Link Cost: " << adj.getLinkCost() << endl;
  os << "Status: " << adj.getStatus() << endl;
  os << "Interest Timed out: " << adj.getInterestTimedOutNo() << endl;
  return os;
}

} //namespace nlsr