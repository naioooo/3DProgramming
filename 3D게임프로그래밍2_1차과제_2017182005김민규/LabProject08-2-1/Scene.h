//-----------------------------------------------------------------------------
// File: Scene.h
//-----------------------------------------------------------------------------

#pragma once

#include "Shader.h"

class CScene
{
public:
    CScene();
    ~CScene();

	bool OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	bool OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);

	void BuildObjects(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList);
	void ReleaseObjects();

	ID3D12RootSignature *CreateGraphicsRootSignature(ID3D12Device *pd3dDevice);
	ID3D12RootSignature *GetGraphicsRootSignature() { return(m_pd3dGraphicsRootSignature); }
	void SetGraphicsRootSignature(ID3D12GraphicsCommandList *pd3dCommandList) { pd3dCommandList->SetGraphicsRootSignature(m_pd3dGraphicsRootSignature); }

	virtual void CreateShaderVariables(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList);
	virtual void UpdateShaderVariables(ID3D12GraphicsCommandList *pd3dCommandList);
	virtual void ReleaseShaderVariables();

	bool ProcessInput(UCHAR *pKeysBuffer);
	void AnimateObjects(float fTimeElapsed, CCamera* pCamera);

	void PrepareRender(ID3D12GraphicsCommandList* pd3dCommandList);
	void Render(ID3D12GraphicsCommandList *pd3dCommandList, CCamera *pCamera=NULL);

	void ReleaseUploadBuffers();

	CHeightMapTerrain *GetTerrain() { return(m_pTerrain); }

	CPlayer						*m_pPlayer = NULL;
	CBulletShader               *m_pBulletShader = NULL;

protected:

	CBillboardShader            *m_pBillboardShader = NULL;

	CExplosiveShader            *m_pExplosiveShader = NULL;

	CEnemyShader                *m_pEnemyShader = NULL;

	CHeightMapTerrain			*m_pTerrain = NULL;
	CSkyBox                     *m_pSkyBox = NULL;

	CTerrainWater				*m_pTerrainWater = NULL;
	XMFLOAT4X4					m_xmf4x4WaterAnimation;

	ID3D12RootSignature			*m_pd3dGraphicsRootSignature = NULL;

public:
	void CheckObjectByBulletCollisions();

};
