/*
* Copyright 2010-2015 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/
#include <aws/s3/model/CORSRule.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::S3::Model;
using namespace Aws::Utils::Xml;
using namespace Aws::Utils;

CORSRule::CORSRule() : 
    m_allowedHeadersHasBeenSet(false),
    m_allowedMethodsHasBeenSet(false),
    m_allowedOriginsHasBeenSet(false),
    m_exposeHeadersHasBeenSet(false),
    m_maxAgeSeconds(0),
    m_maxAgeSecondsHasBeenSet(false)
{
}

CORSRule::CORSRule(const XmlNode& xmlNode) : 
    m_allowedHeadersHasBeenSet(false),
    m_allowedMethodsHasBeenSet(false),
    m_allowedOriginsHasBeenSet(false),
    m_exposeHeadersHasBeenSet(false),
    m_maxAgeSeconds(0),
    m_maxAgeSecondsHasBeenSet(false)
{
  *this = xmlNode;
}

CORSRule& CORSRule::operator =(const XmlNode& xmlNode)
{
  XmlNode resultNode = xmlNode;

  if(!resultNode.IsNull())
  {
    XmlNode allowedHeaderNode = resultNode.FirstChild("AllowedHeader");
    if(!allowedHeaderNode.IsNull())
    {
      while(!allowedHeaderNode.IsNull())
      {
        m_allowedHeaders.push_back(StringUtils::Trim(allowedHeaderNode.GetText().c_str()));
        allowedHeaderNode = allowedHeaderNode.NextNode("AllowedHeader");
      }

      m_allowedHeadersHasBeenSet = true;
    }
    XmlNode allowedMethodNode = resultNode.FirstChild("AllowedMethod");
    if(!allowedMethodNode.IsNull())
    {
      while(!allowedMethodNode.IsNull())
      {
        m_allowedMethods.push_back(StringUtils::Trim(allowedMethodNode.GetText().c_str()));
        allowedMethodNode = allowedMethodNode.NextNode("AllowedMethod");
      }

      m_allowedMethodsHasBeenSet = true;
    }
    XmlNode allowedOriginNode = resultNode.FirstChild("AllowedOrigin");
    if(!allowedOriginNode.IsNull())
    {
      while(!allowedOriginNode.IsNull())
      {
        m_allowedOrigins.push_back(StringUtils::Trim(allowedOriginNode.GetText().c_str()));
        allowedOriginNode = allowedOriginNode.NextNode("AllowedOrigin");
      }

      m_allowedOriginsHasBeenSet = true;
    }
    XmlNode exposeHeaderNode = resultNode.FirstChild("ExposeHeader");
    if(!exposeHeaderNode.IsNull())
    {
      while(!exposeHeaderNode.IsNull())
      {
        m_exposeHeaders.push_back(StringUtils::Trim(exposeHeaderNode.GetText().c_str()));
        exposeHeaderNode = exposeHeaderNode.NextNode("ExposeHeader");
      }

      m_exposeHeadersHasBeenSet = true;
    }
    XmlNode maxAgeSecondsNode = resultNode.FirstChild("MaxAgeSeconds");
    if(!exposeHeaderNode.IsNull())
    {
      m_maxAgeSeconds = StringUtils::ConvertToInt32(StringUtils::Trim(maxAgeSecondsNode.GetText().c_str()).c_str());
      m_maxAgeSecondsHasBeenSet = true;
    }
  }

  return *this;
}

void CORSRule::AddToNode(XmlNode& parentNode) const
{
  Aws::StringStream ss;
  if(m_allowedHeadersHasBeenSet)
  {
   for(const auto& item : m_allowedHeaders)
   {
     XmlNode allowedHeadersNode = parentNode.CreateChildElement("AllowedHeader");
     allowedHeadersNode.SetText(item);
   }
  }

  if(m_allowedMethodsHasBeenSet)
  {
   for(const auto& item : m_allowedMethods)
   {
     XmlNode allowedMethodsNode = parentNode.CreateChildElement("AllowedMethod");
     allowedMethodsNode.SetText(item);
   }
  }

  if(m_allowedOriginsHasBeenSet)
  {
   for(const auto& item : m_allowedOrigins)
   {
     XmlNode allowedOriginsNode = parentNode.CreateChildElement("AllowedOrigin");
     allowedOriginsNode.SetText(item);
   }
  }

  if(m_exposeHeadersHasBeenSet)
  {
   for(const auto& item : m_exposeHeaders)
   {
     XmlNode exposeHeadersNode = parentNode.CreateChildElement("ExposeHeader");
     exposeHeadersNode.SetText(item);
   }
  }

  if(m_maxAgeSecondsHasBeenSet)
  {
   XmlNode maxAgeSecondsNode = parentNode.CreateChildElement("ExposeHeader");
  ss << m_maxAgeSeconds;
   maxAgeSecondsNode.SetText(ss.str());
  ss.str("");
  }

}