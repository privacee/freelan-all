/*
 * libnetlinkplus - A portable netlink extension for Boost::ASIO.
 * Copyright (C) 2010-2011 Julien KAUFFMANN <julien.kauffmann@freelan.org>
 *
 * This file is part of libnetlinkplus.
 *
 * libnetlinkplus is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 3 of
 * the License, or (at your option) any later version.
 *
 * libnetlinkplus is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 *
 * If you intend to use libnetlinkplus in a commercial software, please
 * contact me : we may arrange this for a small fee or no fee at all,
 * depending on the nature of your project.
 */

/**
 * \file protocol.hpp
 * \author Julien KAUFFMANN <julien.kauffmann@freelan.org>
 * \brief netlink protocol implementation.
 */

#pragma once

#include <boost/asio.hpp>

#include <linux/netlink.h>
#include <linux/rtnetlink.h>

#include "endpoint.hpp"

namespace netlink
{
	/**
	 * \brief A netlink protocol class.
	 */
	template <int Protocol>
	class netlink_protocol
	{
		public:

			/**
			 * \brief The endpoint type.
			 */
			typedef netlink_endpoint<netlink_protocol> endpoint;

			/**
			 * \brief The socket type.
			 */
			typedef boost::asio::basic_raw_socket<netlink_protocol> socket;

			/**
			 * \brief Get the associated type.
			 * \return The type.
			 */
			int type() const
			{
				return SOCK_RAW;
			}

			/**
			 * \brief Get the associated protocol.
			 * \return The protocol.
			 */
			int protocol() const
			{
				return Protocol;
			}

			/**
			 * \brief Get the associated family.
			 * \return The family.
			 */
			int family() const
			{
				return AF_NETLINK;
			}
	};

	/**
	 * \brief The route protocol.
	 */
	typedef netlink_protocol<NETLINK_ROUTE> netlink_route_protocol;
}
