/*************************************************************************
 * Copyright (c) 2014 eProsima. All rights reserved.
 *
 * This copy of eProsima RTPS is licensed to you under the terms described in the
 * fastrtps_LIBRARY_LICENSE file included in this distribution.
 *
 *************************************************************************/

/**
 * @file CacheChangePool.h
 *
 */



#ifndef CACHECHANGEPOOL_H_
#define CACHECHANGEPOOL_H_


#include <vector>
#include <cstdint>
#include <cstddef>



namespace eprosima {
namespace fastrtps{
namespace rtps {

struct CacheChange_t;

/**
 * Class CacheChangePool, used by the HistoryCache to pre-reserve a number of CacheChange_t to avoid dynamically reserving memory in the middle of execution loops.
 * @ingroup COMMONMODULE
 */
class CacheChangePool {
public:
	virtual ~CacheChangePool();
	CacheChangePool(uint16_t pool_size,uint32_t payload_size,int32_t max_pool_size);
	//!Reserve a Cache from the pool.
	bool reserve_Cache(CacheChange_t** chan);
	//!Release a Cache back to the pool.
	void release_Cache(CacheChange_t*);
	//!Get the size of the cache vector; all of them (reserved and not reserved).
	size_t get_allCachesSize(){return m_allCaches.size();}
	//!Get the number of frre caches.
	size_t get_freeCachesSize(){return m_freeCaches.size();}

	inline uint32_t getPayloadSize(){return m_payload_size;};
private:
	uint32_t m_payload_size;
	uint16_t m_pool_size;
	int32_t m_max_pool_size;
	std::vector<CacheChange_t*> m_freeCaches;
	std::vector<CacheChange_t*> m_allCaches;
	bool allocateGroup(uint16_t pool_size);
};
}
} /* namespace rtps */
} /* namespace eprosima */

#endif /* CACHECHANGEPOOL_H_ */