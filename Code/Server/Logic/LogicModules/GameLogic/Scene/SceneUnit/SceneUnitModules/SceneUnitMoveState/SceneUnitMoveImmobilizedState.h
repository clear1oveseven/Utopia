#pragma once

#include "SceneUnitMoveState.h"
#include "Common/Utils/Ticker.h"

namespace GameLogic
{
	class SceneUnitMoveImmobilizedState : public SceneUnitMoveState
	{
	public:
		SceneUnitMoveImmobilizedState(SceneUnitMove *move_agent);
		virtual ~SceneUnitMoveImmobilizedState();

		virtual void Enter(void *param);
		virtual void Exit();
		virtual void Update(long deltaMs);
		virtual bool IsDone();
		void ImmobilizeEndMs(long end_ms);
		long GetEndTimestampMs() { return m_end_timestamp_ms; }
		virtual void ForceDone() { m_is_done = true; m_end_timestamp_ms = 0; }

	protected:
		bool m_is_done = true;
		long m_end_timestamp_ms = 0;
		Ticker m_ticker;
	};
}
