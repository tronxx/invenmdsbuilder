object Form_selserie: TForm_selserie
  Left = 304
  Top = 198
  Width = 673
  Height = 515
  Caption = 'Selección de Series'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object grp_foldisp: TGroupBox
    Left = 0
    Top = 0
    Width = 657
    Height = 161
    Align = alTop
    Caption = 'Folios Disponibles'
    TabOrder = 0
    object dxDBGrid1: TdxDBGrid
      Left = 2
      Top = 15
      Width = 653
      Height = 144
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
      OnDblClick = dxDBGrid1DblClick
      OnKeyDown = dxDBGrid1KeyDown
      DataSource = dts_foldisp
      Filter.Criteria = {00000000}
      OptionsDB = [edgoCancelOnExit, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks]
      OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
      OnCustomDrawCell = dxDBGrid1CustomDrawCell
      object dxDBGrid1FOLIO: TdxDBGridMaskColumn
        Caption = 'Folio'
        Sorted = csUp
        Width = 77
        BandIndex = 0
        RowIndex = 0
        FieldName = 'FOLIO'
      end
      object dxDBGrid1SERIE: TdxDBGridMaskColumn
        Caption = 'Serie'
        Width = 122
        BandIndex = 0
        RowIndex = 0
        FieldName = 'SERIE'
      end
      object dxDBGrid1COSTO: TdxDBGridCurrencyColumn
        Caption = 'Costo'
        Width = 51
        BandIndex = 0
        RowIndex = 0
        FieldName = 'COSTO'
      end
      object dxDBGrid1MODENT: TdxDBGridMaskColumn
        Caption = 'S/N'
        Width = 41
        BandIndex = 0
        RowIndex = 0
        FieldName = 'MODENT'
      end
      object dxDBGrid1FECHA: TdxDBGridDateColumn
        Caption = 'Fecha Ent.'
        Width = 90
        BandIndex = 0
        RowIndex = 0
        FieldName = 'FECHA'
      end
      object dxDBGrid1ENTCAN: TdxDBGridMaskColumn
        Caption = 'Ent.Can'
        Width = 69
        BandIndex = 0
        RowIndex = 0
        FieldName = 'ENTCAN'
      end
      object dxDBGrid1FECENTORI: TdxDBGridDateColumn
        Caption = 'F.Ent.Original'
        Width = 108
        BandIndex = 0
        RowIndex = 0
        FieldName = 'FECENTORI'
      end
      object dxDBGrid1FACPRO: TdxDBGridMaskColumn
        Caption = 'Fact.Prove'
        Width = 91
        BandIndex = 0
        RowIndex = 0
        FieldName = 'FACPRO'
      end
    end
  end
  object grp_folsel: TGroupBox
    Left = 0
    Top = 161
    Width = 657
    Height = 315
    Align = alClient
    Caption = 'Folios Seleccionados'
    TabOrder = 1
    object dxDBGrid2: TdxDBGrid
      Left = 94
      Top = 15
      Width = 561
      Height = 298
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
      OnDblClick = dxDBGrid2DblClick
      OnKeyDown = dxDBGrid2KeyDown
      DataSource = dts_folsel
      Filter.Criteria = {00000000}
      OptionsDB = [edgoCancelOnExit, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks]
      OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
      OnCustomDrawCell = dxDBGrid1CustomDrawCell
      object folsel_folio: TdxDBGridMaskColumn
        Caption = 'Folio'
        DisableEditor = True
        Sorted = csUp
        Width = 66
        BandIndex = 0
        RowIndex = 0
        FieldName = 'FOLIO'
      end
      object folsel_serie: TdxDBGridMaskColumn
        Caption = 'Serie'
        CharCase = ecUpperCase
        Width = 141
        BandIndex = 0
        RowIndex = 0
        FieldName = 'SERIE'
      end
      object folsel_costo: TdxDBGridCurrencyColumn
        Caption = 'Costo'
        DisableEditor = True
        Width = 40
        BandIndex = 0
        RowIndex = 0
        FieldName = 'COSTO'
      end
      object folsel_modent: TdxDBGridMaskColumn
        Caption = 'S/N'
        DisableEditor = True
        Width = 31
        BandIndex = 0
        RowIndex = 0
        FieldName = 'MODENT'
      end
      object folsel_fechaent: TdxDBGridDateColumn
        Caption = 'Fecha Ent.'
        DisableEditor = True
        Width = 70
        BandIndex = 0
        RowIndex = 0
        FieldName = 'FECHA'
      end
      object folsel_entcan: TdxDBGridMaskColumn
        Caption = 'Ent.Can'
        DisableEditor = True
        Width = 53
        BandIndex = 0
        RowIndex = 0
        FieldName = 'ENTCAN'
      end
      object folsel_fecentori: TdxDBGridDateColumn
        Caption = 'F.Ent.Original'
        DisableEditor = True
        Width = 83
        BandIndex = 0
        RowIndex = 0
        FieldName = 'FECENTORI'
      end
      object folsel_facpro: TdxDBGridMaskColumn
        Caption = 'Fact.Prove'
        DisableEditor = True
        Width = 73
        BandIndex = 0
        RowIndex = 0
        FieldName = 'FACPRO'
      end
    end
    object pnl_centro: TPanel
      Left = 2
      Top = 15
      Width = 92
      Height = 298
      Align = alLeft
      BevelOuter = bvNone
      TabOrder = 1
      object BitBtn1: TBitBtn
        Left = 8
        Top = 0
        Width = 75
        Height = 42
        Action = Selecciona
        Caption = '&Selecciona'
        TabOrder = 0
        Glyph.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000FF00000000000000
          0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000FF000000FF000000
          FF000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00000000000000
          000000000000000000000000000000000000000000000000FF000000FF000000
          FF000000FF000000FF000000000000000000FF00FF00FF00FF00000000000000
          FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
          FF000000FF000000FF000000FF000000FF000000000000000000000000000000
          000000000000000000000000000000000000000000000000FF000000FF000000
          FF000000FF000000FF000000000000000000FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000FF000000FF000000
          FF000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000FF00000000000000
          0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
        Layout = blGlyphBottom
      end
      object BitBtn2: TBitBtn
        Left = 8
        Top = 49
        Width = 75
        Height = 42
        Action = Elimina
        Caption = '&Elimina'
        TabOrder = 1
        Glyph.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
          0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000000000000000FF000000
          0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF0000000000000000000000FF000000FF000000FF000000
          0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF0000000000000000000000FF000000FF000000FF000000FF000000FF000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
          FF000000FF000000FF000000FF000000FF000000FF0000000000FF00FF00FF00
          FF0000000000000000000000FF000000FF000000FF000000FF000000FF000000
          0000000000000000000000000000000000000000000000000000FF00FF00FF00
          FF00FF00FF00FF00FF0000000000000000000000FF000000FF000000FF000000
          0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000000000000000FF000000
          0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
          0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
        Layout = blGlyphBottom
      end
      object btn_aceptar: TBitBtn
        Left = 8
        Top = 105
        Width = 75
        Height = 25
        TabOrder = 2
        OnClick = btn_aceptarClick
        Kind = bkOK
      end
      object btn_cancelar: TBitBtn
        Left = 8
        Top = 137
        Width = 75
        Height = 25
        Caption = 'Cancelar'
        TabOrder = 3
        OnClick = btn_cancelarClick
        Kind = bkCancel
      end
    end
  end
  object qry_foldisp: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select b.codigo, b.almac, b.costo, b.modent,'
      'b.folio, b.serie, b.fecha,'
      'b.entcan, b.fecentori, facpro, b.prove'
      'from movart b '
      'where codigo = :CODIGO and b.almac = :ALM'
      'and b.fecha <= :FECHAENT and salio <> '#39'S'#39
      'order by folio, serie')
    UpdateObject = uqry_foldisp
    Left = 399
    Top = 216
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
        DataType = ftDate
        Name = 'FECHAENT'
        ParamType = ptUnknown
      end>
  end
  object dts_foldisp: TDataSource
    DataSet = qry_foldisp
    Left = 400
    Top = 184
  end
  object uqry_foldisp: TUpdateSQL
    Left = 400
    Top = 248
  end
  object dts_folsel: TDataSource
    DataSet = qry_folsel
    Left = 368
    Top = 184
  end
  object qry_folsel: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select a.codigo, b.almac, b.costo, b.modent, '
      'b.folio, b.serie, b.fecha,'
      'b.entcan, b.fecentori, facpro, b.prove'
      'from inven a join movart b on a.codigo = b.codigo'
      'where a.codigo = '#39'x'#39' and salio = '#39'N'#39' and salio = '#39'S'#39)
    UpdateObject = uqry_folsel
    Left = 367
    Top = 216
  end
  object uqry_folsel: TUpdateSQL
    Left = 368
    Top = 248
  end
  object ActionList1: TActionList
    Images = dm.ImageList1
    Left = 368
    Top = 152
    object Selecciona: TAction
      Caption = '&Selecciona'
      ImageIndex = 8
      OnExecute = SeleccionaExecute
    end
    object Elimina: TAction
      Caption = '&Elimina'
      ImageIndex = 6
      OnExecute = EliminaExecute
    end
  end
end
