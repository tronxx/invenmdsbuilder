object Frame_datosinternet: TFrame_datosinternet
  Left = 0
  Top = 0
  Width = 525
  Height = 342
  TabOrder = 0
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 525
    Height = 57
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object lbl_oferta: TLabel
      Left = 12
      Top = 9
      Width = 28
      Height = 13
      Alignment = taRightJustify
      Caption = 'T�tulo'
    end
    object Label1: TLabel
      Left = 11
      Top = 33
      Width = 29
      Height = 13
      Alignment = taRightJustify
      Caption = 'Grupo'
    end
    object edt_titulo: TEdit
      Left = 50
      Top = 4
      Width = 327
      Height = 21
      MaxLength = 70
      TabOrder = 0
    end
    object btn_cambiagrp: TBitBtn
      Left = 384
      Top = 24
      Width = 113
      Height = 25
      Action = cambiar_grupo
      Caption = 'Cambiar Grupo'
      TabOrder = 1
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
        0000FF00FF000000000000000000000000000000000000000000FFFFFF00FFFF
        FF0000000000FFFFFF000000000000000000FFFFFF0000000000FFFF00000000
        00000000000000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF0000000000FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFF00000000
        000000FFFF00FFFFFF0000FFFF00FFFFFF00000000000000000000000000FFFF
        FF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF0000000000FFFF00000000
        0000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF000000
        0000FFFFFF000000000000000000FFFFFF00FFFFFF0000000000FFFF00000000
        000000FFFF00FFFFFF0000FFFF00FFFFFF000000000000000000000000000000
        00000000000000FFFF0000000000FFFFFF00FFFFFF0000000000FFFF00000000
        0000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FF
        FF00FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF0000000000FFFF00000000
        000000FFFF00FFFFFF0000000000000000000000000000000000000000000000
        000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
        00000000000000FFFF00FFFFFF0000FFFF00000000000000000000FFFF000000
        0000FFFFFF00FFFFFF000000000000000000FFFFFF0000000000FF00FF00FF00
        FF00FF00FF000000000000000000000000000000000000FFFF0000000000FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF000000000000FFFF0000000000FFFFFF00FFFF
        FF00FFFFFF00FFFFFF0000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF000000000000FFFF0000000000FFFFFF00FFFFFF000000
        000000000000FFFFFF0000000000FFFFFF00FFFFFF0000000000FF00FF00FF00
        FF00FF00FF000000000000FFFF000000000000000000FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF0000000000FFFFFF0000000000FF00FF00FF00FF00FF00
        FF00000000000000FF0000000000FF00FF0000000000FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF000000000000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FF00FF00FF00FF000000000000000000000000000000
        0000000000000000000000000000FF00FF00FF00FF00FF00FF00}
    end
    object DBEdit1: TDBEdit
      Left = 50
      Top = 28
      Width = 327
      Height = 21
      TabStop = False
      DataField = 'descri'
      DataSource = dts_grupointer
      TabOrder = 2
    end
  end
  object GroupBox1: TGroupBox
    Left = 0
    Top = 57
    Width = 525
    Height = 285
    Align = alClient
    Caption = 'Descripci�n'
    TabOrder = 1
    object mmo_descripcion: TMemo
      Left = 2
      Top = 15
      Width = 521
      Height = 268
      Align = alClient
      TabOrder = 0
    end
  end
  object ActionList1: TActionList
    Images = dm.ImageList1
    Left = 416
    Top = 101
    object grabar_datosinternet: TAction
      Caption = 'Grabar'
      ImageIndex = 28
      OnExecute = grabar_datosinternetExecute
    end
    object cambiar_grupo: TAction
      Caption = 'Cambiar Grupo'
      ImageIndex = 1
      OnExecute = cambiar_grupoExecute
    end
  end
  object dts_titulo: TDataSource
    AutoEdit = False
    DataSet = qry_titulo
    Left = 88
    Top = 100
  end
  object qry_titulo: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from observent where codigo = :CODIGO and alm = '#39#39' and'
      '( tipo = :TIPOTITULO or tipo = :TIPODESCRI )'
      'and cia = :CIA'
      'order by conse'
      '')
    UpdateObject = uqry_titulo
    Left = 120
    Top = 100
    ParamData = <
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TIPOTITULO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TIPODESCRI'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object uqry_titulo: TUpdateSQL
    ModifySQL.Strings = (
      'update observent'
      'set'
      '  TIPO = :TIPO,'
      '  ALM = :ALM,'
      '  NUMERO = :NUMERO,'
      '  FECHA = :FECHA,'
      '  CONSE = :CONSE,'
      '  OBSERVS = :OBSERVS,'
      '  CIA = :CIA,'
      '  CODIGO = :CODIGO'
      'where'
      '  TIPO = :OLD_TIPO and'
      '  ALM = :OLD_ALM and'
      '  NUMERO = :OLD_NUMERO and'
      '  FECHA = :OLD_FECHA and'
      '  CONSE = :OLD_CONSE and'
      '  CIA = :OLD_CIA and'
      '  CODIGO = :OLD_CODIGO')
    InsertSQL.Strings = (
      'insert into observent'
      '  (TIPO, ALM, NUMERO, FECHA, CONSE, OBSERVS, CIA, CODIGO)'
      'values'
      
        '  (:TIPO, :ALM, :NUMERO, :FECHA, :CONSE, :OBSERVS, :CIA, :CODIGO' +
        ')')
    DeleteSQL.Strings = (
      'delete from observent'
      'where'
      '  TIPO = :OLD_TIPO and'
      '  ALM = :OLD_ALM and'
      '  NUMERO = :OLD_NUMERO and'
      '  CONSE = :OLD_CONSE and'
      '  CIA = :OLD_CIA and'
      '  CODIGO = :OLD_CODIGO')
    Left = 150
    Top = 100
  end
  object dts_relinv: TDataSource
    AutoEdit = False
    DataSet = qry_relinv
    Left = 88
    Top = 140
  end
  object qry_relinv: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select  d.idrelinv, d.idart, d.idrel, d.iddato, d.conse, b.* fro' +
        'm'
      'inven a join inv_invhist c on a.codigo = c.codigo'
      'and a.cia = c.cia'
      'join inv_relinv d on c.idart = d.idart and d.idrel = :IDREL'
      'join inv_gruposinternet b on d.iddato = b.idgrupo'
      'where a.codigo = :CODIGO and a.cia = :CIA'
      ''
      ' ')
    UpdateObject = uqry_relinv
    Left = 120
    Top = 140
    ParamData = <
      item
        DataType = ftInteger
        Name = 'IDREL'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object uqry_relinv: TUpdateSQL
    ModifySQL.Strings = (
      'update inv_relinv'
      'set'
      '  IDDATO = :IDDATO,'
      '  CONSE = :CONSE'
      'where'
      '  IDRELINV = :OLD_IDRELINV')
    InsertSQL.Strings = (
      'insert into inv_relinv'
      '  (IDRELINV, IDART, IDREL, IDDATO, CONSE)'
      'values'
      '  (:IDRELINV, :IDART, :IDREL, :IDDATO, :CONSE)')
    DeleteSQL.Strings = (
      'delete from inv_relinv'
      'where'
      '  IDRELINV = :OLD_IDRELINV')
    Left = 150
    Top = 140
  end
  object dts_grupointer: TDataSource
    AutoEdit = False
    DataSet = qry_grupointer
    Left = 88
    Top = 180
  end
  object qry_grupointer: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select b.* from  inv_gruposinternet b'
      'where idgrupo = :IDGRUPO'
      '')
    Left = 120
    Top = 180
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'IDGRUPO'
        ParamType = ptUnknown
      end>
  end
  object qry_idart: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from  inv_invhist where codigo = :CODIGO and cia = :CIA'
      ' ')
    Left = 120
    Top = 284
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_invhist: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from inv_invhist where codigo = :CODIGO and cia = :CIA'
      '')
    Left = 120
    Top = 212
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object DataSource1: TDataSource
    AutoEdit = False
    DataSet = qry_invhist
    Left = 88
    Top = 212
  end
end
