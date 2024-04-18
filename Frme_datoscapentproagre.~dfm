object Frame_datoscapentproagre: TFrame_datoscapentproagre
  Left = 0
  Top = 0
  Width = 684
  Height = 185
  TabOrder = 0
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 684
    Height = 49
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label8: TLabel
      Left = 6
      Top = 22
      Width = 33
      Height = 13
      Caption = 'Código'
    end
    object Label12: TLabel
      Left = 345
      Top = 22
      Width = 42
      Height = 13
      Caption = 'Cantidad'
      FocusControl = edt_canti
    end
    object Label6: TLabel
      Left = 422
      Top = 21
      Width = 41
      Height = 13
      Caption = 'Costo U.'
    end
    object Label10: TLabel
      Left = 572
      Top = 22
      Width = 22
      Height = 13
      Caption = 'Folio'
    end
    object edt_codigo: TEdit
      Left = 47
      Top = 18
      Width = 113
      Height = 21
      CharCase = ecUpperCase
      TabOrder = 0
      OnExit = edt_codigoExit
      OnKeyDown = edt_codigoKeyDown
    end
    object DBEdit4: TDBEdit
      Left = 161
      Top = 18
      Width = 177
      Height = 21
      TabStop = False
      DataField = 'DESCRI'
      DataSource = dts_inven
      TabOrder = 1
    end
    object edt_canti: TdxCurrencyEdit
      Left = 391
      Top = 18
      Width = 26
      TabOrder = 2
      OnExit = edt_cantiExit
      Alignment = taRightJustify
      DecimalPlaces = 0
      DisplayFormat = '0'
      Value = 1
      StoredValues = 1
    end
    object edt_costou: TdxCurrencyEdit
      Left = 465
      Top = 18
      Width = 100
      TabOrder = 3
      Alignment = taRightJustify
      DisplayFormat = '$,0.00;-$,0.00'
      StoredValues = 1
    end
    object edt_folios: TdxEdit
      Left = 599
      Top = 18
      Width = 74
      TabOrder = 4
      TabStop = False
      CharCase = ecUpperCase
      MaxLength = 15
      ReadOnly = True
      StoredValues = 66
    end
  end
  object grp_series: TGroupBox
    Left = 0
    Top = 49
    Width = 684
    Height = 136
    Align = alClient
    Caption = 'Series'
    TabOrder = 1
    Visible = False
    object dbgrd_renentra: TdxDBGrid
      Left = 2
      Top = 40
      Width = 680
      Height = 94
      Bands = <
        item
        end>
      DefaultLayout = True
      HeaderPanelRowCount = 1
      KeyField = 'FOLIO'
      SummaryGroups = <>
      SummarySeparator = ', '
      Align = alClient
      TabOrder = 0
      OnKeyDown = dbgrd_renentraKeyDown
      ArrowsColor = clInfoBk
      DataSource = dts_datosped
      Filter.Criteria = {00000000}
      OptionsDB = [edgoCancelOnExit, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks, edgoUseLocate]
      OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoIndicator, edgoRowSelect, edgoUseBitmap]
      object dbgrd_renentraFOLIO: TdxDBGridMaskColumn
        Caption = 'Folio'
        BandIndex = 0
        RowIndex = 0
        FieldName = 'FOLIO'
      end
      object dbgrd_renentraSERIE: TdxDBGridMaskColumn
        Caption = 'Serie'
        BandIndex = 0
        RowIndex = 0
        FieldName = 'SERIE'
      end
      object dbgrd_renentraSERIEMOT: TdxDBGridMaskColumn
        Caption = 'Serie Motor'
        BandIndex = 0
        RowIndex = 0
        FieldName = 'SERIEMOT'
      end
      object dbgrd_renentraPEDTO: TdxDBGridMaskColumn
        Caption = 'Pedimento'
        BandIndex = 0
        RowIndex = 0
        FieldName = 'PEDTO'
      end
      object dbgrd_renentraADUANA: TdxDBGridMaskColumn
        Caption = 'Aduana'
        BandIndex = 0
        RowIndex = 0
        FieldName = 'ADUANA'
      end
      object dbgrd_renentraFECHAPED: TdxDBGridDateColumn
        Caption = 'Fecha Pedimento'
        BandIndex = 0
        RowIndex = 0
        FieldName = 'FECHAPED'
      end
    end
    object Panel2: TPanel
      Left = 2
      Top = 15
      Width = 680
      Height = 25
      Align = alTop
      BevelOuter = bvNone
      TabOrder = 1
      object SpeedButton7: TSpeedButton
        Left = 210
        Top = 2
        Width = 100
        Height = 21
        Action = modifica_serie
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
    end
  end
  object qry_inven: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select codigo, descri, tipo, costos, coston, piva, precio, linea'
      'from inven where codigo = :CODIGO and cia = :CIA order by codigo')
    Left = 207
    Top = 45
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_inven: TDataSource
    DataSet = qry_inven
    Left = 239
    Top = 45
  end
  object qry_folsigent: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select codigo,ultfol,alm,cia from exist'
      'where '
      'codigo = :CODIGO and  alm = :ALM and cia = :CIA')
    UpdateObject = uqry_folsigent
    Left = 103
    Top = 45
    ParamData = <
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ALM'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object uqry_folsigent: TUpdateSQL
    ModifySQL.Strings = (
      'update exist'
      'set'
      '  CODIGO = :CODIGO,'
      '  ULTFOL = :ULTFOL,'
      '  ALM = :ALM,'
      '  CIA = :CIA'
      'where'
      '  CODIGO = :OLD_CODIGO and'
      '  ALM = :OLD_ALM and'
      '  CIA = :OLD_CIA')
    InsertSQL.Strings = (
      'insert into exist'
      '  (CODIGO, ULTFOL, ALM, CIA)'
      'values'
      '  (:CODIGO, :ULTFOL, :ALM, :CIA)')
    DeleteSQL.Strings = (
      'delete from exist'
      'where'
      '  CODIGO = :OLD_CODIGO and'
      '  ALM = :OLD_ALM and'
      '  CIA = :OLD_CIA')
    Left = 136
    Top = 45
  end
  object qry_datosped: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select folio, serie, b.concepto as seriemot,'
      'b.concepto as pedto,'
      'b.concepto as aduana,'
      'a.fecha as fechaped'
      'from movart a join conceps b on a.nompro = b.ncon'
      'where codigo = '#39'-1'#39' and folio = -1'
      ''
      ' '
      ' ')
    UpdateObject = uqry_datosped
    Left = 271
    Top = 45
  end
  object dts_datosped: TDataSource
    DataSet = qry_datosped
    Left = 303
    Top = 45
  end
  object ActionList1: TActionList
    Images = dm.ImageList1
    Left = 440
    Top = 129
    object agrega_serie: TAction
      Caption = 'Volver a Capturar Series'
      ImageIndex = 29
      OnExecute = agrega_serieExecute
    end
    object modifica_serie: TAction
      Caption = 'Modifica'
      ImageIndex = 1
      OnExecute = modifica_serieExecute
    end
  end
  object uqry_datosped: TUpdateSQL
    Left = 336
    Top = 45
  end
end
